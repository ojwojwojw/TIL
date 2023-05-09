<template>
  <div>
      <h1>GameScene: {{currentScene()}} </h1>

      <div v-if="currentScene() == 1">
        <GameScene1/>
      </div>
      <div v-if="currentScene() == 2">
        <GameScene2/>
      </div>
      
  </div>
</template>

<script>
import GameScene1 from './components/GameScene1.vue';
import GameScene2 from './components/GameScene2.vue';

export default {
  name: 'App',
  methods: {
    currentScene() {
      return this.$store.state.GameScene_cnt
    }
  },
  data() {
    return{

    }
  },
  components: {
    GameScene1,
    GameScene2,
  }
}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}

.chat-box{
  border: 2px solid black;
  width: 1580px;
  height: 320px;
  margin: 5px;

  position:absolute; 
  bottom: 10px;

  background-color: rgb(159, 212, 233 ,0.5);
}

.profile-img{
  border: 2px solid black;
  width: 280px;
  height: 280px;
  margin: 15px 5px 5px 5px ;

  background-color: white;
}

.text-box{
  border: 1px solid black;
  width: 1380px;
  height: 300px;
  margin: 10px;

  background-color: rgba(255, 255, 255, 0.1);
  
}

.game-background{
  border: 2px solid black;
  width: 1600px;
  height:900px;
  margin: 10px;
}

.option{
  border-radius: 10px;
  border: 2px solid black;
  width: 300px;
  height: 200px;
  background-color: rgb(159, 212, 233 ,0.5);
  
  z-index: 1;

  position: absolute;
  top: 30%;
  left: 35%;
}

.next-button{
  position: absolute;
  bottom: 10px;
  right: 10px;
  height: 100px;
  margin: 5px;

  width: 150px;
  background-color: rgb(196, 212, 245);
}

.select-button{
  position: relative;
  top: 20px;
  left: 30px;
  margin: 20px;


  height: 50px;
  width: 200px;
  background-color: rgb(196, 212, 245);
}

.center-character{
  position: absolute;
  top: 10%;
  left: 25%;

  height: 500px;
  width: 500px;
   
}

.background {
  width: 1596px;
  height:896px;

  background-size: cover;
  object-fit: cover;
  z-index: -1;
}
</style>
