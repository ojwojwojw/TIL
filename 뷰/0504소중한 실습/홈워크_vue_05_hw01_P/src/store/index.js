import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    counter: 0,
  },
  getters: {
  },
  mutations: {
    muta1 (state){
      state.counter += 1
      console.log(state.counter)
    },
    muta2 (state){
      state.counter -= 1
    }

  },
  actions: {
    increase: function () {
      this.$store.commit("muta1")
    },
    decrease: function () {
      this.$store.commit("muta2")
    },
  },
  modules: {
  }
})
