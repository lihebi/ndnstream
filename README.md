# 运行

```
./a.sh
```

# 前提

要有修改过的`ndnsim`和`ns-3`安装在标准位置.即`./waf install`

# 过程说明

## consumer

只发送一个`/video/0`的interest。
打印出收到的所有data。

## Provider

当收到`interest`时，若其最后一个部分是数字（活着另外一个特性，能够表示其是要求一个流），
就美一秒钟发一次data。

每次发送的data名，都是在上一个的基础上数字递增。

## 执行结果

```
1s 0 StreamConsumer:SendInterest(): Send Interest for: /video/0
1.02048s 2 StreamProducer:OnInterest(): Received Interest: /video/0
1.02048s 2 StreamProducer:SendData(): Send Data for: /video/0
Insert pit:/video/1
Insert pit:/video/1
Insert pit:/video/1
1.04114s 0 StreamConsumer:OnData(): Received Data for: /video/0
2.02048s 2 StreamProducer:SendData(): Send Data for: /video/1
Insert pit:/video/2
Insert pit:/video/2
Insert pit:/video/2
2.04114s 0 StreamConsumer:OnData(): Received Data for: /video/1
3.02048s 2 StreamProducer:SendData(): Send Data for: /video/2
Insert pit:/video/3
Insert pit:/video/3
Insert pit:/video/3
3.04114s 0 StreamConsumer:OnData(): Received Data for: /video/2
4.02048s 2 StreamProducer:SendData(): Send Data for: /video/3
Insert pit:/video/4
Insert pit:/video/4
Insert pit:/video/4
4.04114s 0 StreamConsumer:OnData(): Received Data for: /video/3
5.02048s 2 StreamProducer:SendData(): Send Data for: /video/4
Insert pit:/video/5
Insert pit:/video/5
Insert pit:/video/5
5.04114s 0 StreamConsumer:OnData(): Received Data for: /video/4
6.02048s 2 StreamProducer:SendData(): Send Data for: /video/5
Insert pit:/video/6
Insert pit:/video/6
Insert pit:/video/6
6.04114s 0 StreamConsumer:OnData(): Received Data for: /video/5
7.02048s 2 StreamProducer:SendData(): Send Data for: /video/6
Insert pit:/video/7
Insert pit:/video/7
Insert pit:/video/7
7.04114s 0 StreamConsumer:OnData(): Received Data for: /video/6
8.02048s 2 StreamProducer:SendData(): Send Data for: /video/7
Insert pit:/video/8
Insert pit:/video/8
Insert pit:/video/8
8.04114s 0 StreamConsumer:OnData(): Received Data for: /video/7
```

## Future Work

consumer可以检测有哪些没收到，并重发相应interest。
