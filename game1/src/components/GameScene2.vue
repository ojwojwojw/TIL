<template>
  <div>
    <div class="game-background">
  
      <div class="center-character">
        <img v-if="script_cnt>=6" src="@/assets/violet0.png" alt="" class="center-character">  
      </div>   

      <img v-if="script_cnt>=12" src="@/assets/background0.png" alt="" class="background">

      <div v-if="show_option()" class= "option">
        <button class="select-button">
          선택지1 : 게임씬 4로 간다.
        </button>
        <br>
        <button class="select-button">
          선택지2 : 게임씬 5으로 간다.
        </button>
      </div>

      <div class="chat-box d-flex" >
        <img :src="profile_src" alt ="" class="profile-img">
        
        <div class="text-box">
          <h3>{{script[script_cnt][1]}}</h3>
          <button @click ="add_script_cnt" class="next-button">다음</button>
        </div>
        
      </div>
    </div>
  </div>
</template>

<script>
import player from "@/assets/player.png"
import violet from "@/assets/violet0.png"

export default {
  data() {
    
    return {
      script_cnt: 0,
      profile_src: player, // 프로필 이미지 초기화
      script: [
        [player,"여기로 왔다는건 무사히 게임씬 2로 왔다는거네요."]  ,  //0
        [player,"vuex를 사용해서 적절히 state를 변경하는데에 성공하셨겠군요."],
        [player,"게임씬 1을 안보이게 잘 처리 하셨나요?"],
        [player,"하지막 아직 구현할게 너무 많아요."],
        [player,"이런 비주얼 노블 게임은 다른 캐릭터가 화면 중앙에 등장해야해요"],
        [player,"자 이 대사가 끝나면 등장하게 될거에요"],
        [player,"짜잔~" ] ,//6
        [player,"그리고 이 게임개발자는 저녁밥을 먹으면서 이걸 떠올리고 말았죠"],
        [player,"캐릭터가 등장한다고 해서 끝이 아니에요"],
        [violet,"다른 캐릭터가 말할땐 그 캐릭터의 이미지가 프로필에 떠야죠"],
        [player,"대사정보를 담은 리스트에 이미지경로 정보도 담을 필요가 있겠어요"],
        [violet,"그리고 배경도 띄워야해요."], //11
        [violet,"짜잔"] ,//12
        [player,"그리고 곧 선택지가 떠서 또 다른 게임씬으로 가겠죠"],
        [violet,"이정도면 기본 구색은 갖춘거 같아요"],
      ]
    }
  },
  computed: {
  },
  methods: {
    add_script_cnt() {
      this.script_cnt += 1;
      this.profile_src = this.script[this.script_cnt][0]
    },
    show_option () {
      if(this.script_cnt >= this.script.length-1){
        return true
      }
    },  
  }
}
</script>

<style>

</style>