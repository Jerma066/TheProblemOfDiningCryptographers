import asyncio
import socket
import yaml

CONFIG_NAME = "сonfig.yaml"


class DiningServer:
    def __init__(self):
        with open(CONFIG_NAME) as f:
            cfg = yaml.load(f)

        self.ip_address = socket.gethostbyname(socket.getfqdn())
        self.port_for_writing = cfg['self_parameters']['port_for_writing']
        self.port = cfg['self_parameters']['port_for_reading']
        self.num_of_cryptographers = cfg['self_parameters']['num_of_cryptographers']
        self.key_words = cfg['self_parameters']['receive_message']
        self.map_of_guests = {}
        self.current_number = 0
        self.num_code = cfg['client_parameters']['send_number_code']
        self.map_code = cfg['client_parameters']['send_map_code']

        self.loop = asyncio.get_event_loop()
        corut = asyncio.start_server(self.read_data_from_socket, self.ip_address, self.port, loop=self.loop)
        self.server = self.loop.run_until_complete(corut)

        print(socket.gethostbyname(socket.getfqdn()))

        try:
            self.loop.run_forever()
        except KeyboardInterrupt:
            self.server.close()
            self.loop.run_until_complete(self.server.wait_closed())
            self.loop.close()

    async def read_data_from_socket(self, reader, writer):
        data = await reader.read(1024)

        message = data.decode()
        address = writer.get_extra_info("peername")

        current_address = address[0]

        if message == self.key_words:
            if current_address not in self.map_of_guests:
                self.map_of_guests[current_address] = self.current_number
                answer = str(self.num_code) + ' ' + str(self.current_number)

                self.send_answer_to_user(answer, current_address)

                self.current_number += 1
                print(self.map_of_guests)

        print("received %r from %r" % (message, address))

        if len(self.map_of_guests) is self.num_of_cryptographers:
            self.stop_reading()

        writer.close()

    def send_answer_to_user(self, answer, host):
        sock = socket.create_connection((host, self.port_for_writing))
        sock.sendall(answer.encode())
        sock.close()

    def stop_reading(self):
        for address in self.map_of_guests:

            answer = str(self.map_code) + ' ' + str(self.map_of_guests)
            print(address)
            print(answer)
            self.send_answer_to_user(answer, address)

        print(self.map_of_guests)
        raise KeyboardInterrupt


if __name__ == '__main__':
    server = DiningServer()
