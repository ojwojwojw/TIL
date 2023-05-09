<template>
  <div>
    <div class="game-background d-flex">
      
      <div v-if="show_option()" class= "option">
        <button class="select-button" @click="GoToScene2" >
          선택지1 : 게임씬 2로 간다.
        </button>
        <br>
        <button class="select-button" @click="GoToScene3" >
          선택지2 : 게임씬 3으로 간다.
        </button>
      </div>

      <div class="chat-box d-flex" >
        <img src="@/assets/player.png" alt="" class="profile-img">
        
        <div class="text-box">
          <h3>{{script[script_cnt]}}</h3>
          <button @click ="add_script_cnt" class="next-button">다음</button>
        </div>
        
      </div>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      SceneData : null,
      script_cnt: 0,
      script: [
        "반갑습니다.",
        "이건 대사 테스트에요",
        "잘 될지 모르겠네요",
        "슬슬 마지막 대사가 와요",
        "마지막 대사가 끝나면 선택지를 띄워야겠죠."
      ]
    }
  },
  methods: {
    add_script_cnt() {
      this.script_cnt += 1;
    },
    show_option () {
      if(this.script_cnt >= this.script.length-1){
        return true
      }
    }, 
    GoToScene2 () {
      const newScene = 2
      this.$store.dispatch('changeScene',newScene)
    } ,
    GoToScene3 () {
      const newScene = 3
      this.$store.dispatch('changeScene',newScene)
    } 
  }
}
</script>

<style>

</style>