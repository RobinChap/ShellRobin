int core(); //coeur logiciel
char* cmd_entry(char* in, char* out);//r�cup�ration entr�e utilasteur
char* read_cmd(char* in, char* out);
char* call_function(char *in, char* out);
int paramIs(int number, char* func);


char* cmd_pwd(char* retour);
char* cmd_cd(char* pwd, char* target);
int cmd_mkdir(char* pwd, char* name);
char* cmd_printf(int nbPram);
char* cmd_debug();
