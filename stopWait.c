#include <stdio.h>
#include <stdlib.h>

int main() {

    int frame = 1;
    int total_frames;

    printf("Enter total number of frames to send: ");
    scanf("%d", &total_frames);

    while (frame < total_frames) {
        // Sender sends frame
        printf("\nSender: Sending frame %d\n", frame);

        // Simulate successful reception
        printf("Receiver: Frame %d received correctly\n", frame);
        printf("Receiver: ACK sent for frame %d\n", frame);

        // Move to next frame
        frame++;
    }

    printf("\nAll frames sent successfully using Stop-and-Wait ARQ.\n");
    return 0;
}

