import pygame


class Alien:
    def __init__(self, energy=50, life=50):
        self.energy = energy
        self.life = life
        pass
    def move(self, dm, movX, movY, speed = 1):
        pass
    def fire(self, x, y, speed = 1, weaponStregth= 1):
        #speed and wepon strength will be added depending on level
        pass