import pygame


class Missle:
    def __init__(self, x, y, speed):
        self.x = x
        self.y = y 
        self.speed = speed
        self.gunOne = (self.x + 15, self.y + 10)
        self.missileImg = pygame.image.load('missile.gif')
        self.rect = self.missileImg.get_rect()
        print('missle')
        self.misX = self.gunOne[0]
        self.misY = self.gunOne[1]
        
    def fireGunOne(self):
        print('Fire')
        self.misY -= self.speed
        
        