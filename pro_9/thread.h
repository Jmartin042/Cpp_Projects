// this is a utility function which creates a thread with a given integer id
// theoretically eachc thread runs independently and in parallel
// but, since we only have one physical computer, they run in time-sharing fashion
// on the same computer; 
int call_from_thread(int id, int x, int y, int a, int b) {
cout << "Start thread id: " << id << " x: " << x << " and y: " << y << "\n" << endl;

	 int MATCH = 1;
	 //if (x < (IMAGE_PROC::n-IMAGE_PROC::f+1) && y < (IMAGE_PROC::n-IMAGE_PROC::f+1))
	 if (x < (a-b+1) && y < (a-b+1))
	 {
		for(int i = 0; i < b && MATCH == 1; i++)
		{
			for(int j = 0; j < b && MATCH == 1; j++)
			{
				if (image[x+i][y+j] != filter[i][j])
				{
					MATCH = 0;
				}
				else {}
			}
		}
	 }
	 else
	 {
//cout << "In else: points too close to the edges; skip; make MATCH = 0; " << endl;
		 MATCH = 0;
	 }
	 result[id] = MATCH;
	 result_x[id] = x;
	 result_y[id] = y;
	return MATCH;
}
