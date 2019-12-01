// don't forget the usual top comments

class GraphTopSort extends Graph {
	
	// set all predecessor counts to 0
	public void initPredCounts() {

	}

	public void outputTopSort() {
		Vertex_Node[] zeroPredecessorQueue = new Vertex_Node[this.size];
		Vertex_Node[] topSort = new Vertex_Node[this.size];
		int queueFront = 0, queueBack = 0, outputCt = 0;
		Edge_Node e;
		Vertex_Node v = this.head;
		
		initPredCounts();
		
		// set the predecessor counts by visiting all the edges and
		// incrementing the target predecessor counts of these edges
		
		// implement as simple nested while loops
		while (v != null) {

		}
		
		// find vertices with predecessor counts of 0 and put them on the queue
		// this will be a while loop
		
		
		// the main loop
		// remove a vertex from the zero queue, add it to the topSort array,
		// and traverse its edges to update target predecessor counts -- if any
		// become 0, add to the zero queue
		while (queueBack != queueFront) {  // while the queue is not empty
			
		}
		
		// check if every vertex has been put in the topSort array and either output it
		// on one line or report "loop"
		
		// Your output should match mine exactly
		
		
	}

	public static String myName() {
		return "Santa Claus";
	}
}

