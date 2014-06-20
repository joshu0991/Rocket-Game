import pygame


class Missle:
    def __init__(self, x, y, speed):
        self.x = x
        self.y = y 
        self.speed = speed
        self.missileImg = pygame.image.load('missile.png')
        self.misX = 0
        self.misY = 0
        
    def fireGunOne(self):
        gunOne = (self.x + 17, self.y)
        self.misX = gunOne[0]
        self.misY = gunOne[1]
        self.misY += self.speed
        
        