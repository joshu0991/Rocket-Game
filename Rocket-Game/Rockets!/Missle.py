import pygame


class Missle(pygame.sprite.Sprite):
    def __init__(self, x, y, speed, side, tracker):
        pygame.sprite.Sprite.__init__(self)
        self.x = x
        self.y = y
        self.tracker = tracker
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
        
    #if hit deal damage render cool graphic
    #XY is the aliens posoition
    def explode(self, x, y, damage=10):
        if self.x == x and self.y == y:
            return ('t', self.tracker)
        else: return ('f')
        # if hit return true and use result to update score
        pass
    def checkHit(self):
        pass