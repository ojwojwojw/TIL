// store/index.js

import axios from 'axios'

export default new Vuex.Store({
  state: {
    todoList: [],
  },
  mutations: {
    TODO_LIST_SUCCESS: function (state, payload) {
      state.todoList = payload.data
    },
  },
  actions: {
    fetchTodoList: async function ({ commit }) {
      const requestUrl = 'http://localhost:8000/api/v1/todos/'

      const response = await axios.get(requestUrl)
      commit('TODO_LIST_SUCCESS', response)
    },
  },
})


