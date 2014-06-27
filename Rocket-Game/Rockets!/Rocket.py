
import pygame

class Rocket:
    
    def __init__(self):
        self.rocketImg =pygame.image.load('RocketShip.gif')
        self.x = 1
        self.y = 1
        
    def move(self, dm, movX, movY):
        self.x += movX * dm
        self.y += movY * dm
        