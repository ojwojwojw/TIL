import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    GameScene_cnt:1
  },
  getters: {
  },
  mutations: {
    CHANGE_SCENE(state,SceneData){
      state.GameScene_cnt = SceneData
    }
  },
  actions: {
    changeScene(context,SceneData){
      console.log(SceneData)
      context.commit('CHANGE_SCENE' , SceneData)
    }
  },
  modules: {
  }
})
