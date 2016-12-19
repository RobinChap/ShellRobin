int core(); //coeur logiciel
char* cmd_entry(char* in, char* out);//récupération entrée utilasteur
char* read_cmd(char* in, char* out);
char* call_function(char *in, char* out);
int paramIs(int number, char* func);


char* cmd_pwd(char* retour);
char* cmd_short_pwd(char* retour);
void cmd_print_cmd(char* p_message);
char* cmd_cd(char* pwd, char* target);
int cmd_mkdir(char* pwd, char* name);
char* cmd_printf(int nbPram);
char* cmd_debug();
char* cmd_shutdown();
