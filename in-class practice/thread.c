int counter = 0 ;

void* run_thread(void * noarg){
	int i = 0;
	for( i = 0; i < 1000; i++){
		counter++;
	}
	 pthread_exit(NULL);
	return NULL;
}

void* my_thread(int argc,  *vargp){
	pthread_t thid;
	void *ret;

	if (pthread_create(&thid, NULL, thread, "thread 1") != 0) {
	  perror("pthread_create() error");
	  exit(1);
	}

	if (pthread_join(thid, &ret) != 0) {
	  perror("pthread_create() error");
	  exit(3);
	}
	
	prinf("The value in counter is %d\n", counter);
	exit(EXIT_SUCCESS);
}