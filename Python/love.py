import turtle
import time

def LittleHeart():
    for i in range(200):
        turtle.right(1)
        turtle.forward(2)

love = "跟随灵魂找到你"
me = '@Mandy24'

turtle.title="soul"

turtle.setup(width=900, height=500)
turtle.color('pink', 'pink')
turtle.pensize(10)
turtle.speed(1)
turtle.up()
turtle.hideturtle()
turtle.goto(0, -180)
turtle.showturtle()
turtle.down()
turtle.speed(1)
turtle.begin_fill()
turtle.left(140)
turtle.forward(224)
LittleHeart()
turtle.left(120)
LittleHeart()
turtle.forward(224)
turtle.end_fill()
turtle.pensize(5)
turtle.up()
turtle.hideturtle()
turtle.goto(0, 0)
turtle.showturtle()
turtle.color('#FFF', 'white')
turtle.write(love, font=('微软雅黑', 24,), align="center")
turtle.up()
turtle.hideturtle()
time.sleep(2)

if me != '':
    turtle.color('black', 'pink')
    time.sleep(2)
    turtle.goto(180, -180)
    turtle.showturtle()
    turtle.write(me,  font=('微软雅黑', 18,), align="center", move=True)

window = turtle.Screen()
window.exitonclick()