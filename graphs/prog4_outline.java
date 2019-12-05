// don't forget the usual top comments

import java.util.*;

class GraphTopSort extends Graph {
	
	public void initPredCounts() {

		/* Initialize to 0 */
		for (Vertex_Node navigator = head; navigator != null; navigator = navigator.getNext())
			navigator.setPredCt(0);

		/* Initialize to actual values by traversing edgelist of each vertex */
		for (Vertex_Node navigator = head; navigator != null; navigator = navigator.getNext())
			for (Edge_Node edgeNavigator = navigator.getNbrList(); edgeNavigator != null; edgeNavigator = edgeNavigator.getNext())
				edgeNavigator.getTarget().setPredCt(edgeNavigator.getTarget().getPredCt()+1);
	}

	public void outputTopSort() {

		Vertex_Node[] zeroPredecessorQueue;
		Vertex_Node[] topSort;
		Edge_Node edgeNavigator;
		Vertex_Node navigator;
		int queueFront, queueBack, outputCount;
		boolean entered;

		zeroPredecessorQueue = new Vertex_Node[this.size];
		topSort = new Vertex_Node[this.size];
		queueBack = queueFront = outputCount = 0;
		entered = false;

			initPredCounts();
			while (outputCount < this.size) {

				/* Traverse Vertex Node list and remove nodes with 0 predecessors */
				for (navigator = head; navigator != null; navigator = navigator.getNext())

					if (navigator.getPredCt() == 0) {

						/* Push the node to the queue */
						zeroPredecessorQueue[queueBack++] = navigator;
						navigator.setPredCt(-1);

						/* Set to make sure there was at the very least, one node has no
						 * predecessors (check for cycles)  */
						entered = true;
					}


				/* If there were no nodes without predecessors, a loop exists */
				if (!entered) {
					System.out.println("Loop");
					break;
				}

				/* Reset the 'entered' flag and begin processesing the queue */
				entered = false;

				while (queueFront != queueBack) {
					for (navigator = zeroPredecessorQueue[queueFront++], edgeNavigator = navigator.getNbrList();
						 edgeNavigator != null; edgeNavigator = edgeNavigator.getNext())
						edgeNavigator.getTarget().setPredCt(edgeNavigator.getTarget().getPredCt() - 1);
					topSort[outputCount++] = zeroPredecessorQueue[queueFront-1];
				}
			}
			for (int i = 0; i < outputCount; ++i)
				System.out.print(topSort[i].getName() + " ");
	}

	public static String myName() {
		return "Santa Claus";
	}
}

