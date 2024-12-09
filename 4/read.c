#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_NAME "fifo"
#define BUFFER_SIZE 256

int main() {
    char buffer[BUFFER_SIZE];
    int fifo_fd;

    fifo_fd = open(FIFO_NAME, O_RDONLY);
    if (fifo_fd == -1) {
        perror("Ошибка открытия FIFO");
        exit(EXIT_FAILURE);
    }

    printf("Ожидание данных...\n");
    while (1) {
        if (read(fifo_fd, buffer, BUFFER_SIZE) > 0) {
            printf("Получено: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0) {
                break;
            }
        }
    }
    close(fifo_fd);
    return 0;
}
