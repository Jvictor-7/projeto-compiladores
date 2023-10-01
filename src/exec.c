#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

int main(void) {
    // Variáveis
    const char *pdfFile = "file:///C:/Users/joao0/projeto-compiladores/assets/teste.pdf";
    const char *mp4File = "file:///C:/Users/joao0/projeto-compiladores/assets/teste.mp4";
    const char *linkMeet = "https://meet.google.com/";
    const char *linkWhatsapp = "https://chat.whatsapp.com/CjJ6dB9PiayLFAUAfs1Vq3";
    const char *linkGmail = "https://mail.google.com/mail/u/0/#inbox?compose=new";

    const char *endEdge = "taskkill /F /IM chrome.exe";

    char command[512];
    int opc = 0;

    printf("Escolha um programa para abrir\n\n");
    printf("\t1 - Abrir PDF no Chrome\n\n");
    printf("\t2 - Abrir video no Chrome\n\n");
    printf("\t3 - Abrir o link do Meet\n\n");
    printf("\t4 - Abrir um link do Whatsapp\n\n");
    printf("\t5 - Abrir um link do Gmail\n\n");

    printf("Opcao: ");
    scanf("%d", &opc);

    // 1 - Abrir PDF no Chrome
    // 2 - Abrir video no Chrome
    // 3 - Abrir uma reunião do Meet no Chrome (podendo ser limitada por tempo)
    // 4 - Abrir um link do whatsapp no Chrome
    // 5 - Abrir um link de email no Chrome

    switch(opc){
        case 1:
            snprintf(command, sizeof(command), "start chrome \"%s\"", pdfFile);
            system(command);
            break;
        case 2:
            snprintf(command, sizeof(command), "start chrome \"%s\"", mp4File);
            system(command);
            break;
        case 3:
            snprintf(command, sizeof(command), "start chrome \"%s\"", linkMeet);
            system(command);

            time_t startTime = time(NULL); // Obter a hora atual
            int minutos = 0;
            int limite = 2; // Varíavel que define o tempo limite em minutos

            if (limite != -1 ){ // Caso o limite seja diferente de -1, temos um limite de tempo
                while (minutos < limite) { // Contador de minutos até o limite de tempo
                    time_t currentTime = time(NULL);
                    int segundosPassados = difftime(currentTime, startTime);

                    if (segundosPassados >= 60) {
                        startTime = currentTime;
                        minutos++;
                        printf("Ja se passaram %d Minutos...\n", minutos);

                        if (minutos == limite - 5) {
                            const char *message = "Em 5 minutos sua reuniao sera encerrada automaticamente.";
                            const char *title = "Alerta";
                            
                            MessageBox(NULL, message, title, MB_ICONWARNING | MB_OK);
                        }
                        if (minutos == limite - 1) {
                            const char *message = "Em 1 minuto sua reuniao sera encerrada automaticamente.";
                            const char *title = "Alerta";
                            
                            MessageBox(NULL, message, title, MB_ICONWARNING | MB_OK);
                        }
                        if (minutos == limite) {
                            const char *message = "Reuniao encerrada!.";
                            const char *title = "Alerta";
                            
                            MessageBox(NULL, message, title, MB_ICONWARNING | MB_OK);

                            snprintf(command, sizeof(command), "%s", endEdge);
                            system(command);
                        }
                    }
                }
            }
            // Caso o limite seja -1, não temos um limite de tempo e não precisamos fechar o programa
            break;
        case 4:
            snprintf(command, sizeof(command), "start chrome \"%s\"", linkWhatsapp);
            system(command);
            break;
        case 5:
            snprintf(command, sizeof(command), "start chrome \"%s\"", linkGmail);
            system(command);
            break;
        default:
            printf("\n\nDesculpe, esta opção é invalida. O programa será encerrado. \n\n");
    }

    return 0;
}