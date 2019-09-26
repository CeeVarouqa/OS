//Created by CeeVarouqa
int main(int argc, char **argv) 
{
    int process_id = fork();

    if (process_id > 0) 
    {
        sleep(10);
        kill(process_id, SIGKILL);
        printf("Killed :3 \n");
    } 
    else if (!process_id) 
    {
        while(1)
        {
            printf("I'm alive\n");
            sleep(1);
        }
    }

}