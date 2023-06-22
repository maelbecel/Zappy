##
## EPITECH PROJECT, 2023
## clientAi
## File description:
## testAi
##

from ..ai.clientAi import clientAi as clientAI

import neat
import pickle
import threading
from neat.nn import FeedForwardNetwork


class testAi:
    def __init__(self, teamName: str, port: int, host: str):
        self.configFile = "src/ai/neat-config-file.yml"
        self.population = None
        self.generations = 100
        self.teamName = teamName
        self.port = port
        self.host = host
        self.stats = None

    def getRessources(self):
        """
        The function gets the resources available in the game and appends them to
        the inputData list.

        @return It is not clear what is being returned as there is a return
        statement missing in the code snippet.
        """
        temp = dict()

        self.look()
        for element in self.inv:
            if element == "player":
                continue
            temp[element] = 0
        temp["player"] = 0
        if self.lookResult == []:
            return
        for element in self.lookResult[0]:
            temp[element] += 1
        for element in temp:
            self.inputData.append(temp[element])

    def getInventory(self):
        """
        This function retrieves the inventory data and appends it to the inputData
        list.
        """
        self.inventory()
        for element in self.inv:
            self.inputData.append(self.inv[element])

    def isABroadcast(self):
        """
        This function checks if a message is empty or not and returns 0 if it is
        empty and 1 if it is not.

        @return If the message attribute of the object is empty, the function
        returns 0. Otherwise, it returns 1. This function is checking if the object
        represents a broadcast message or not.
        """
        if self.message == "":
            return 0
        return 1

    def evaluateGenome(self, genome, config, fitnesses, mutex):
        """
        This function evaluates a genome by using a neural network to make
        decisions for a client in a game, and updates the genome's fitness value
        based on the client's actions and success in the game.

        @param genome a genetic algorithm genome, which represents a neural network
        @param config A configuration object that contains various parameters for
        the neural network, such as the number of input and output nodes, the
        activation function, and the mutation rates.
        @param fitnesses A list that stores the fitness values of each evaluated
        genome.
        @param mutex A mutex (short for mutual exclusion) is a programming
        construct used to prevent multiple threads from accessing shared resources
        simultaneously, which can lead to race conditions and other synchronization
        issues. In this context, the mutex is used to ensure that only one thread
        at a time can update the fitness value of the genome and
        """
        client = clientAI(self.teamName, self.port, self.host)
        client.connect()
        fitness = 0
        while client.alive:
            net = FeedForwardNetwork.create(genome, config)
            client.getInventory()
            client.getRessources()
            client.inputData.append(client.isABroadcast())
            count = 16 - client.inputData.__len__()
            if count > 0:
                for i in range(count):
                    client.inputData.append(0)
            if client.inputData.__len__() > 16:
                continue
            output = net.activate(client.inputData)
            max_index = output.index(max(output))
            client.inputData = []
            if max_index == 0:
                client.forward()
            elif max_index == 1:
                client.right()
            elif max_index == 2:
                client.left()
            elif max_index == 3:
                client.look()
            elif max_index == 4:
                client.inventory()
            elif max_index == 5:
                client.broadcast("incantation")
            elif max_index == 6:
                client.connectNbr()
            elif max_index == 7:
                client.fork()
            elif max_index == 8:
                client.eject()
            elif max_index == 9:
                client.take("food")
                fitness += 2.0
            elif max_index == 10:
                client.set("food")
                fitness += -0.01
            elif max_index == 11:
                success = client.incantation()
                if success:
                    fitness += 10.0
            elif max_index == 12:
                client.take("linemate")
                fitness += 0.6
            elif max_index == 13:
                client.set("linemate")
            elif max_index == 14:
                client.take("deraumere")
                fitness += 0.6
            elif max_index == 15:
                client.set("deraumere")
            elif max_index == 16:
                client.take("sibur")
                fitness += 0.6
            elif max_index == 17:
                client.set("sibur")
            elif max_index == 18:
                client.take("mendiane")
                fitness += 0.6
            elif max_index == 19:
                client.set("mendiane")
            elif max_index == 20:
                client.take("phiras")
                fitness += 0.6
            elif max_index == 21:
                client.set("phiras")
            elif max_index == 22:
                client.take("thystame")
                fitness += 0.6
            elif max_index == 23:
                client.set("thystame")
            fitness += 0.0
        mutex.acquire()
        genome.fitness = fitness  # Set the fitness value of the genome
        fitnesses.append(fitness)
        mutex.release()
        client.disconnect()

    def loadConfig(self):
        """
        This function loads a NEAT configuration file, creates a population, and
        adds reporters to track the progress of the evolution.
        """
        # Load the NEAT configuration file
        self.config = neat.Config(
            neat.DefaultGenome,
            neat.DefaultReproduction,
            neat.DefaultSpeciesSet,
            neat.DefaultStagnation,
            self.configFile,
        )
        # Create the population
        self.population = neat.Population(self.config)

        # Add a reporter to track the progress of the evolution
        self.population.add_reporter(neat.StdOutReporter(True))
        self.stats = neat.StatisticsReporter()
        self.population.add_reporter(self.stats)

    def run(self):
        """
        This function runs the NEAT algorithm for a specified number of
        generations, evaluates the fitness of each genome in the population using
        multithreading, and saves the best genome as a pickle file.
        """
        # Run the NEAT algorithm for the specified number of generations
        self.loadConfig()

        for generation in range(self.generations):
            print(f"Generation {generation + 1}")
            genomes = list(self.population.population.values())

            fitnesses = []
            threads = []
            # Create a mutex
            mutex = threading.Lock()
            for genome in genomes:
                # Create thread objects with arguments
                threads.append(
                    threading.Thread(
                        target=self.evaluateGenome,
                        args=(genome, self.config, fitnesses, mutex),
                    )
                )
                threads[-1].start()

            for thread in threads:
                thread.join()
            best_fitness = max(fitnesses)
            average_fitness = sum(fitnesses) / len(fitnesses)
            print(f"Best Fitness: {best_fitness}")
            print(f"Average Fitness: {average_fitness}")
            # self.population.run_fitness_function(genomes)
        print("Evolution complete")
        best_genome = max(self.population.population.values(), key=lambda x: x.fitness)
        print(f"Best genome:\n{best_genome}")
        self.bestBoy = best_genome
        with open("winner.pkl", "wb") as f:
            pickle.dump(best_genome, f)
            f.close()


# TODO: Use the best genome to perform predictions or other tasks
