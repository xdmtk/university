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

		int frontMarker, queueFront, queueBack, outputCount;
		boolean entered;

		zeroPredecessorQueue = new Vertex_Node[this.size];
		topSort = new Vertex_Node[this.size];
		frontMarker = queueBack = queueFront = outputCount = 0;
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
					frontMarker = queueFront;
					for (navigator = zeroPredecessorQueue[queueFront++], edgeNavigator = navigator.getNbrList();
						 edgeNavigator != null; edgeNavigator = edgeNavigator.getNext())
						edgeNavigator.getTarget().setPredCt(edgeNavigator.getTarget().getPredCt() - 1);

					if (queueBack - frontMarker > 1)
						sortQueueGroup(zeroPredecessorQueue, frontMarker, queueBack);
					topSort[outputCount++] = zeroPredecessorQueue[queueFront-1];
				}
			}
			for (int i = 0; i < outputCount; ++i)
				System.out.print(topSort[i].getName() + " ");
	}

	/* Need to get the grouping in the queue to print out alphabetically - Needs work */
	public static void sortQueueGroup(Vertex_Node[] pq, int f, int b) {
		for (int i = f+1, x = 0; x < b-1; ++i, ++x)
			if (pq[i].getName().compareTo(pq[i-1].getName()) > 0) {
				Vertex_Node temp = pq[x];
				int j = i;
				while (j > f && temp.getName().compareTo(pq[j-1].getName()) > 0)
					pq[i] = pq[--i];
				pq[i] = temp;
			}
	}

	public static String myName() {
		return "Santa Claus";
	}
}

