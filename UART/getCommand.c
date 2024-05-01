void getCommand(char *command, int length)
{
					for(i=0;i<length;i++)
          {
						char character;
						character = UART_InChar();
						if(character != CR)
            {
							command[i] = character;
							UART_OutChar(command[i]);
						}
						else if(character == CR || i == length) break;
					}
	}
