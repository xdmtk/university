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

		zeroPredecessorQueue = new Vertex_Node[this.size];
		topSort = new Vertex_Node[this.size];
		queueBack = queueFront = outputCount = 0;

			initPredCounts();
			for (navigator = head; navigator != null; navigator = navigator.getNext())
				if (navigator.getPredCt() == 0)
					zeroPredecessorQueue[queueBack++] = navigator;

			for (queueFront = queueFront; queueFront != queueBack; queueFront++)



	}

	public static String myName() {
		return "Santa Claus";
	}
}

