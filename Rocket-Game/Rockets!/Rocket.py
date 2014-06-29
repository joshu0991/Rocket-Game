import pygame

class Rocket(pygame.sprite.Sprite):
    
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.rocketImg =pygame.image.load('RocketShip.gif')
        self.x = 200
        self.y = 600
        self.shelds = 100
        self.energy = 100
        
    def move(self, dm, movX, movY):
        self.x += movX * dm
        self.y += movY * dm
        
    def chargeBeam(self, x, y, powerUp=1):
        pass
    def increaseLife(self, amout=2):
        pass
    def decramentLife(self, amount=2):
        pass
    def increaseEnergy(self, amount=2):
        pass
    def decreaseEnergy(self):
        pass
    