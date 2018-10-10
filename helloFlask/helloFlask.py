from flask import Flask

app=Flask(__name__)

@app.route('/')

def hello()->str:
    """this is a function"""
    return 'hello flask!'

app.run()