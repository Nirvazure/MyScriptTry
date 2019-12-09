// 定义名为 todo-item 的新组件
Vue.component("todo-item", {
  props: ["todo"],
  template: "<li>{{todo.text}}</li>"
});

var app = new Vue({
  el: "#app",
  data: {
    addItem: "",
    message: "Hello Vue!",
    message2: "页面加载于 " + new Date().toLocaleString(),
    seen: true,
    todos: [
      { text: "学习 JavaScript" },
      { text: "学习 Vue" },
      { text: "整个牛项目" }
    ],
    groceryList: [
      { id: 0, text: "蔬菜" },
      { id: 1, text: "奶酪" },
      { id: 2, text: "随便其它什么人吃的东西" }
    ],
    question: "",
    answer: "I cannot give you an answer until you ask a question!"
  },
  methods: {
    reverseMessage: function() {
      this.message = this.message
        .split("")
        .reverse()
        .join("");
    },
    addNew: function() {
      this.todos.push({ text: this.addItem + new Date().toLocaleString() });
    },
    getAnswer: function() {
      if (this.question.indexOf("?") === -1) {
        this.answer = "Questions usually contain a question mark. ;-)";
        return;
      }
      this.answer = "Thinking...";
      var vm = this;
      axios
        .get("https://yesno.wtf/api")
        .then(function(response) {
          vm.answer = _.capitalize(response.data.answer);
        })
        .catch(function(error) {
          vm.answer = "Error! Could not reach the API. " + error;
        });
    }
  },
  watch: {
    question: function(newQuestion, oldQuestion) {
      this.answer = "Waiting for you to stop typing...";
      this.debouncedGetAnswer();
    }
  },
  created: function() {
    // `_.debounce` 是一个通过 Lodash 限制操作频率的函数。在这个例子中，我们希望限制访问 yesno.wtf/api 的频率
    this.debouncedGetAnswer = _.debounce(this.getAnswer, 500);
  }
});
