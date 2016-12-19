#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"
#include "LibPerso.h"

#define TAILLE_STRING_MAX 100
#define PARAM_MAX 10

static FILE* fichier = NULL;
static char param[PARAM_MAX][TAILLE_STRING_MAX];
static int debug = 0;
static int retour = 1;


int core(){
    char in[TAILLE_STRING_MAX] = "";
    char out[TAILLE_STRING_MAX] = "";



    if(debug){ printf(call_function(in, out)); }
    else{ call_function(in, out); }

    return retour;
}

char* call_function(char* in, char* out){
    int i = 0, nbParam = 0;

    if(debug){ printf(cmd_entry(in, out)); }
    else{ cmd_entry(in, out); }

    for(i = 0; i < PARAM_MAX; i++){
        if(param[i][0] != '\0'){
            nbParam++;
        }
    }

    if(nbParam == 0){
        return "ERROR : no function called\n";
    }

        if(paramIs(0, "printf")){
            if(debug){ printf(cmd_printf(nbParam)); }
            else{ cmd_printf(nbParam); }
        }
        else if(paramIs(0, "debug")){
            if(debug){ printf(cmd_debug()); }
            else{ cmd_debug(); }
        }
        else if(paramIs(0, "shutdown")){
            if(debug){ printf(cmd_shutdown()); }
            else{ cmd_shutdown(); }
        }
        else if(paramIs(0, "pwd")){
            cmd_print_cmd(cmd_pwd(out));
        }
        else if(paramIs(0, "cd")){
            cmd_cd(cmd_pwd(out), param[1]);
        }
        else{
             printf("%s is unknown (Extern function not supported yet)\n", param[0]);
             return "Error: Unknown function";
        }


    return "1";

}



int paramIs(int number, char* func){
    if(strcasecmp(param[number], func) == 0){
     return 1;
    }
    else{
        return 0;
    }
}

char* cmd_entry(char* in, char* out){
    printf("%s : %s />", "Robin", cmd_short_pwd(out)); //a changer
    fgets(in, TAILLE_STRING_MAX, stdin);
    clean(in, stdin);
    return read_cmd(in, out);
}

char* read_cmd(char* in, char* out){

    char* token;
    const char sep[2] = " ";
    int i = 0, compteur = 0;
    for(i = 0; i < PARAM_MAX; i ++){
        param[i][0] = '\0';
    }


    token = strtok(in, sep);
    while(token != NULL && compteur < PARAM_MAX){
        sprintf(param[compteur],"%s", token);
        token = strtok(NULL, sep);
        compteur ++;
    }
    if(compteur >= PARAM_MAX){
        return "ERROR : too much arguments, not supported\n";
    }
    return "1";

}

char* cmd_printf(int nbParam){
    int i = 0;
     for(i = 1; i < nbParam; i++){
                printf(param[i]);
            }
     return "1";
}

char* cmd_debug(){
    if(paramIs(1, "on") && debug == 0){
        debug = 1;
        printf("Debug mode ON\n");
        return "1";
    }
    else if(paramIs(1, "off") && debug == 1){
        debug = 0;
        printf("Debug mode OFF\n");
        return "1";
    }
    else if((paramIs(1, "on") && debug == 1) || (paramIs(1, "off") && debug == 0)){
      printf("Debug mode already on this state\n");
      return "0";
    }
    else{
        printf("Wrong parameter \n accepted : on/off\n");
        return "ERROR WRONG PARAMETER";
    }
}

char* cmd_pwd(char* retour){

    fichier = fopen("pwd.sc", "r");
    fgets(retour, TAILLE_STRING_MAX, fichier);
    fclose(fichier);
    return retour;
}

char* cmd_short_pwd(char* retour){ //a modifier

    fichier = fopen("pwd.sc", "r");
    fgets(retour, TAILLE_STRING_MAX, fichier);
    fclose(fichier);
    return retour;
}

char* cmd_cd(char* pwd, char* target){

    if(target[0] != '\0'){
        fichier = fopen("pwd.sc", "w+");
        fprintf("%s/%s", pwd, target);
        fclose(fichier);
        return "1";
    }
    else{
        printf("Error : no target path entered\n");
        return "0";
    }

}

void cmd_print_cmd(char* p_message){
    printf("%s\n", p_message);
}

char* cmd_shutdown(){
    printf("Turning down ... \n Goodbye");
    retour = 0;
    return "1";
}
