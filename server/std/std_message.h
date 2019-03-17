typedef enum run_status_0001
{
	SUCCEED,WORNNING,ERROR
}run_status;
typedef struct std_message_0001
{
	run_status status;
	char * std_m;
}std_message;
