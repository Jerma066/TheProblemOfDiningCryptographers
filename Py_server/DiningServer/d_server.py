import asyncio
import yaml

CONFIG_NAME = "сonfig.yaml"


class DiningServer:
    def __init__(self):
        with open(CONFIG_NAME) as f:
            cfg = yaml.load(f)

        self.ip_address = cfg['self_parameters']['address']
        self.port = cfg['self_parameters']['port']
        self.num_of_cryptographers = cfg['self_parameters']['num_of_cryptographers']
        self.answer_str = cfg['self_parameters']['reply_message']
        self.key_words = cfg['self_parameters']['receive_message']
        self.map_of_guests = {}
        self.current_number = 1

        self.loop = asyncio.get_event_loop()
        corut = asyncio.start_server(self.read_data_from_socket, self.ip_address, self.port, loop=self.loop)
        self.server = self.loop.run_until_complete(corut)

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

        current_address = address

        if message == self.key_words:
            if current_address not in self.map_of_guests:
                self.map_of_guests[current_address] = self.current_number
                answer = self.answer_str + str(self.current_number)
                writer.write(answer.encode())

                self.current_number += 1
                print(self.map_of_guests)

        print("received %r from %r" % (message, address))

        if len(self.map_of_guests) is self.num_of_cryptographers:
            self.stop_reading()

        writer.close()

    def stop_reading(self):
        print(self.map_of_guests)
        """
        Нужен код, котрый преобразует map_of_guests в формат, 
        который будет удобен для использования пользвоателям.
        
        После чего нужно разослать всем адресам из  map_of_guests
        полученное сообщение, чтобы они имели у себя такой словарь
        """
        raise KeyboardInterrupt


if __name__ == '__main__':
    server = DiningServer()
