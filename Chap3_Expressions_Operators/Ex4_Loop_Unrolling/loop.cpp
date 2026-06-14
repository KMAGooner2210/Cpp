int sum_array(const int arr[4]){
	int sum = 0;
	for(int i = 0; i < 4; i++){
		sum += arr[i];
	}
	return sum;
}

int main(){
	int my_arr[4] = {10, 20 , 30 ,40};
	int total = sum_array(my_arr);
	return total;
}
