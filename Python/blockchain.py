import hashlib
import json
from datetime import time
from time import sleep

#需要引入JSON的数据解析包，sleep引入是为了方便结果的展示，time类负责时间戳，Hash函数由hashlib库提供
from flask import Flask, request, jsonify

class Blockchain:

    def __init__(self):
        self.chain=[]
        self.current_transactions=[]

        self.new_block(proof=100,previous_hash=1)

    def new_block(self,proof,previous_hash):
        """创建区块的方法，输入为工作量和上个区块哈希，创世区块不需要第三个参
        数，加上时间戳，链长度加1，确定工作量以及事务列表，链封装完成后清空交易信息，将区块加在链上"""

        block={
        'index':len(self.chain)+1,
        'timestamp':time(),
        'transcations':self.current_transactions,
        'proof':proof,
        'previous_hash':previous_hash or self.hash(self.chain[-1])
        }

        self.current_transactions=[] #交易信息清空
        self.chain.append(block)

        return block

    def new_transaction(self,sender,recipient,amount):
        """this function is to create an new transaction info includes sender,recipient and amount of transaction"""
        self.current_transactions.append(
            {
                'sender':sender,
                'recipient':recipient,
                'amount':amount
            }
        )

    @staticmethod
    def hash(block):
        """静态方法，使用hashlib的sha256方法计算块的哈希值"""
        block_string=json.dumps(block,sort_keys=True).encode()
        hashlib.sha256()    #使用这个Hash函数,传参block为Jason对象
        return hashlib.sha256(block_string).hexdigest()

    @property 
    def last_block(self):
        """属性方法，返回链上最后一个区块"""
        return self.chain(-1)

    def proof_of_work(self,last_proof) ->int:
        """返回工作量，输入为上一个哈希值，proof作为一个累加量和迭代器表示工作量的多少"""
        proof=0 
        while self.valid_proof(last_proof,proof) is False:
            proof += 1

        print(proof)
        return proof

    def valid_proof(self,last_proof:int,proof:int)->bool:
        guess=f'{last_proof}{proof}'.encode()
        guess_hash=hashlib.sha256(guess).hexdigest()

        print(guess_hash)
        # sleep(1)
        return guess_hash[0:4]=="0000"


#下面为测试代码
# testPow=Blockchain()
# testPow.proof_of_work(102) #测试，假设上一个Hash是100


app=Flask(__name__)
blockchain=Blockchain()

if __name__=='__main__':
    app.run(host='192.168.0.19',port=5000)

@app.route('/transaction/new',methods=['POST'])
def new_transaction():
    values=request.get_jason()
    required=["sender","recipient","amount"]

    if values is None:
        return "Missing values",400

    if not all(k in values for k in required):
        return "Missing values",400

    index=blockchain.new_transaction(values['sender'],values['recipient'],values['amount'])

    response={"message":f'transaction will be added to Block{index}'}
    return jsonify(response),201
    # POST请求通常返回201


@app.route('/mine',methods=['GET'])
def mine():
    """挖矿实现"""
    return "we will mine a new block"

@app.route('/chain',methods=['GET'])
def full_chain():
    response={'chain':blockchain.chain,  'length':len(blockchain.chain) }
    return jsonify(response)

