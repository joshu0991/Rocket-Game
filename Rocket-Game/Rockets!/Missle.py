import pygame


class Missle:
    def __init__(self, x, y, speed, side):
        self.x = x
        self.y = y 
        self.speed = speed
        self.side = side
        self.missileImg = pygame.image.load('missile.gif')
        if side == 'l':
            self.gunOne = (self.x + 15, self.y + 10)
            self.misX = self.gunOne[0]
            self.misY = self.gunOne[1]
        elif side == 'r':
            self.gunTwo = (self.x + 104, self.y + 10)
            self.misX = self.gunTwo[0]
            self.misY = self.gunTwo[1]
        self.rect = self.missileImg.get_rect()
                
    def fire(self):
        self.misY -= self.speed
        
        