#include "server.h"

int main(int argc, char const *argv[]) {
	if(argc != 4){
		printf("Usage: %s <HTTP PORT> <Log File> <DocumentRootFolder>\n",
			   argv[0]);
		return 1;
	}

	int PORT = atoi(argv[1]);
	const char *LOGFILE = argv[2];
	const char *PATH = argv[3];

	char *document_root_folder = malloc(MAX_PATH_LENGTH);
	getcwd(document_root_folder, MAX_PATH_LENGTH);
	strcat(document_root_folder, "/");
	strcat(document_root_folder, PATH);

	int server_socket; /* , client_socket, address_length; */
	/* struct sockaddr_in address; */

	server_socket = create_socket();
	setup_server(server_socket, PORT);
	printf("Listening for connections...\n");
	handle_connection(server_socket, document_root_folder, LOGFILE);
	close(server_socket);
	return 0;
}
