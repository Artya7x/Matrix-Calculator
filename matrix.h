#define mxr 100
#define mxc 100
//Header File
class matrix{
	
	public:
	void read(bool); 
	void print(bool);
	void inverse();
	void addition();
	void subtraction();
	void multiplication();
	
	private:	
		int row,col,row1,col1;
		float array[mxr][mxc],array2[mxr][mxc],array3[mxr][mxc];
		float det;
};
