/** 
 * @description 汇率计算器
 */

// 币种简写及兑换成人民币映射表
var ExchangeMap = {
    USD: {
        name: '美元',
        rate: 7.0384
    },
    EUR: {
        name: '欧元',
        rate: 7.8471
    },
    JPY: {
        name: '日元',
        rate: 0.06638
    },
    CNY: {
        name: '人民币',
        rate: 1
    }
};

/**
 * 汇率计算器类，其他辅助函数可以自行添加
 */
function Calculator() {
    this.bindEvent();
}

Calculator.prototype = {
    /**
     * DOM事件绑定
     * 点击事件：click
     * 键盘事件: keyup / keydown / keypress
     * 切换事件：select change
     */
    bindEvent: function() {

    },

    /**
     * 币种转换主入口函数
     * @param {String} fromValue 待兑换金额
     * @param {String} fromCurrency 源币种
     * @param {String} toCurrency 目标币种
     * @return {String} toValue 兑换金额
     */
    exchange: function(fromValue, fromCurrency, toCurrency) {
        var toValue;

        // todo

        return toValue;
    }

    // 其他辅助函数可自行添加
}