// App.vue

<template>
  <div id="app">
    <p>Counter: {{ counter }}</p>
    <p>Counter x2: {{ counterDouble }}</p>
    <p></p>
    <button @click="action1">increase +</button>
    <button @click="action2">decrease -</button>
  </div>
</template>

<script>
export default {
  name: 'App', 
  methods: {
    action1(){
      this.$store.dispatch('increase')
    },
    action2(){
      this.$store.dispatch('decrease')
    },

  },
  computed: {
    counterDouble: function () {
      return this.counter * 2
    },
  },
}
</script>

<style>
</style>