import pygame


class Alien(pygame.sprite.Sprite):
    def __init__(self, x, y, position, energy=50, life=50):
        pygame.sprite.Sprite.__init__(self)
        self.alienImg =pygame.image.load('AlienShip.gif')
        self.energy = energy
        self.life = life
        self.x = x
        self.y = y
        self.position = position #spot in list
        pass
    def move(self, dm, movX, movY, speed = 1):
        pass
    def fire(self, x, y, speed = 1, weaponStregth= 1):
        #speed and wepon strength will be added depending on level
        pass