
class CLI:
    def __init__(self):
        self.commands = {
            'help': self.help,
            'exit': self.exit
        }
    
    def help(self):
        print('Commands:')
        for command in self.commands:
            print(command)

    def exit(self):
        print('Exiting...')
        exit()

    def run(self):
        while True:
            command = input('Enter a command: ')
            if command in self.commands:
                self.commands[command]()
            else:
                print('Invalid command')

def main():
    cli = CLI()
    cli.run()

if __name__ == '__main__':
    main()
