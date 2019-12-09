## HCI_DEMO
#### Author:LFR  Date:2019.11.07
### Requirements
This project contains two parts
1. a DAG API integrate tools
2. a DAG interactive tools

Refer
* ARC (Chrome plugin)
* rest_client (JAR)

Function
* Map Creator
* DAG Flow Animation

### Todos
* split components(拆分组件，数据流展示，对话)
* gRPC to JS
* 字段分析

---

底部组件
<div>
    <select>
        <option value='1'>语音</option>
        <option value='1'>图像</option>
        <option value='1'>相机</option>
    </select>
    <input placeholder="这是输入文字消息"></input>
    <button display="block">发送</button>
</div>

## Project setup
```
npm install
```

### Compiles and hot-reloads for development
```
npm run serve
```

### Compiles and minifies for production
```
npm run build
```

### Customize configuration
See [Configuration Reference](https://cli.vuejs.org/config/).
