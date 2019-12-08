import java.util.*;
/*
"C:\Program Files\JetBrains\IntelliJ IDEA 2019.2.1\jbr\bin\java.exe" "-javaagent:C:\Program Files\JetBrains\IntelliJ IDEA 2019.2.1\lib\idea_rt.jar=50337:C:\Program Files\JetBrains\IntelliJ IDEA 2019.2.1\bin" -Dfile.encoding=UTF-8 -classpath C:\Users\overc\IdeaProjects\cosci282\graphs\out\production\graphs TestTopologicalSort
		Test #1:  Topological Sort  -- Nicholas Martinez
		=======
		g a d b e c f
		Test #2:  Topological Sort  -- Nicholas Martinez
		=======
		Loop

		Test #3:  Topological Sort  -- Nicholas Martinez
		=======
		f l c e g k d b i h a j
		=======
		f l c e g k d b i h a j
		Done with Nicholas Martinez's test run.

		Process finished with exit code 0
*/

class GraphTopSort extends Graph {
	
	public void initPredCounts() {

		/* Initialize to 0 */
		for (Vertex_Node v = head; v != null; v = v.getNext())
			v.setPredCt(0);

		/* Initialize to actual values by traversing edgelist of each vertex */
		for (Vertex_Node v = head; v != null; v = v.getNext())
			for (Edge_Node e = v.getNbrList(); e != null; e = e.getNext())
				e.getTarget().setPredCt(e.getTarget().getPredCt()+1);
	}

	public void outputTopSort() {

		Vertex_Node[] zeroPredecessorQueue;
		Vertex_Node[] topSort;
		Edge_Node e;
		Vertex_Node v;

		int queueFront, queueBack, outputCount;
		boolean entered, looped;

		zeroPredecessorQueue = new Vertex_Node[this.size];
		topSort = new Vertex_Node[this.size];
		queueBack = queueFront = outputCount = 0;
		entered = looped = false;


			initPredCounts();
			while (outputCount < this.size) {

				/* Traverse Vertex Node list and remove nodes with 0 predecessors */
				for (v = head; v != null; v = v.getNext())

					if (v.getPredCt() == 0) {

						/* Push the node to the queue */
						zeroPredecessorQueue[queueBack++] = v;
						v.setPredCt(-1);

						/* Set to make sure there was at the very least, one node has no
						 * predecessors (check for cycles)  */
						entered = true;
					}


				/* If there were no nodes without predecessors, a loop exists */
				if (!entered) {
					System.out.println("Loop");
					looped = true;
					break;
				}

				/* Reset the 'entered' flag and begin processesing the queue */
				entered = false;

				/* Process the edgelist of each node in the Queue - Pushing newly orphaned
				 * nodes into the Queue as well */
				while (queueFront != queueBack) {

					/* Walk the edgelist for the first unprocessed node in the Queue */
					for (v = zeroPredecessorQueue[queueFront++], e = v.getNbrList(); e != null; e = e.getNext()) {

						/* Decrement the connected vertex nodes */
						e.getTarget().setPredCt(e.getTarget().getPredCt() - 1);

						/* If the newest updated Vertex node is now without a predecessor, push it to
						 * the queue */
						if (e.getTarget().getPredCt() == 0) {
							zeroPredecessorQueue[queueBack++] = e.getTarget();

							/* Disconnect it from the graph by setting pred count to arbitrary negative value */
							e.getTarget().setPredCt(-1);
						}
					}

					topSort[outputCount++] = zeroPredecessorQueue[queueFront-1];
				}
			}

			/* If no cycle is detected, print out the contents of the top sort */
			for (int i = 0; !looped && i < outputCount; ++i)
				System.out.print(topSort[i].getName() + " ");
	}


	public static String myName() {
		return "Nicholas Martinez";
	}
}

