#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "fifo"
#define BUFFER_SIZE 256

int main() {
    char buffer[BUFFER_SIZE];

    mkfifo(FIFO_NAME, 0666);

    int fifo_fd = open(FIFO_NAME, O_WRONLY);
    if (fifo_fd == -1) {
        perror("Ошибка открытия FIFO");
        exit(EXIT_FAILURE);
    }

    printf("Введите данные (введите 'exit' для завершения):\n");
    while (1) {
        printf("> ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (write(fifo_fd, buffer, strlen(buffer) + 1) == -1) {
            perror("Ошибка записи в FIFO");
            close(fifo_fd);
            exit(EXIT_FAILURE);
        }

        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }

    close(fifo_fd);
    return 0;
}
