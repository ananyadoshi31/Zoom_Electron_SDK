<template>
  <div class="meeting">
    <el-button type="primary" round plain @click="getAuthResult">GetAuthResult</el-button>
    <el-button type="primary" round plain @click="getLoginStatus">GetLoginStatus</el-button>
    <el-button type="primary" round plain @click="getWebinalLegalNoticesPrompt">GetWebinalLegalNoticesPrompt</el-button>
    <el-button type="primary" round plain @click="getWebinalLegalNoticesExplained">GetWebinalLegalNoticesExplained</el-button>
    <el-button type="primary" round plain @click="logout">Logout</el-button>
  </div>
  <div class="result">Result: {{result}}</div>
</template>

<script setup lang="ts">
import { ref } from 'vue'
import { ZoomLoginStatus } from '../../../lib/settings.js'
import { getSDKResult } from '../../assets/ts/util'
const remote = window.require('@electron/remote')
const zoomAuth = remote.app.zoomSdkModule.Auth
const result = ref()

const getAuthResult = () => {
  let ret = zoomAuth.GetAuthResult()
  result.value = getSDKResult('GetAuthResult', ret)
}

const getLoginStatus = () => {
  let ret = zoomAuth.GetLoginStatus()
  let desc = Object.keys(ZoomLoginStatus).find(k => ZoomLoginStatus[k] == ret)
  result.value = `GetLoginStatus - ${desc}`
}

const getWebinalLegalNoticesPrompt = () => {
  let ret = zoomAuth.GetWebinalLegalNoticesPrompt()
  result.value = getSDKResult('GetWebinalLegalNoticesPrompt', ret)
}

const getWebinalLegalNoticesExplained = () => {
  let ret = zoomAuth.GetWebinalLegalNoticesExplained()
  result.value = getSDKResult('GetWebinalLegalNoticesExplained', ret)
}

const logout = () => {
  let ret = zoomAuth.Logout()
  result.value = getSDKResult('Logout', ret)
}
</script>
