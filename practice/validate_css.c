#include <stdio.h>
#include <ctype.h>

int main () {
	char text[1000];
	int i = 0, counter = 0, incr = 0, err, n;

	fscanf (stdin, "%s", text);

	while (1) {
		if (text[i] == '{') {
			incr = 1;

			while (incr == 1) {
				if (text[i] == '}') {
					incr = 0;
				}

				i++;
			}
		}

		if (text[i] == '#') {
			if (text[i + 1] == 'e') {
				n = i + 2;

				while (1) {
					if (text[n] == '{') {
						counter++;
						break;
					}
						
					if (isalnum(text[n])) {
						err = 1;
						break;
					}

					n++;
				}
			}
		}
		else {
			i++;
		}

		if (text[i + 2] == '\0') {
			break;
		}
	}

	fprintf (stdout, "%i %i", err, counter);

	return 0;
}
