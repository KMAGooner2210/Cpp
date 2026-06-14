int main(){
	double value = 9.99;
	double* d_ptr = &value;
	
	int* i_ptr = static_cast<int*>(d_ptr);
	return 0;
}
