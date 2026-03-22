uint8_t header[44];
fread(header, sizeof(uint8_t), 44, input);
fwrite(header, sizeof(uint8_t), 44, output);
int16_t buffer;
while (fread(&buffer, sizeof(int16_t), 1, input)) {
    buffer *= factor; fwrite(&buffer, sizeof(int16_t), 1, output);
}
