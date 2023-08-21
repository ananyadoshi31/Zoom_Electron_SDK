<template>
  <div class="meeting">
    <el-button type="primary" round plain @click="setMeetingAudioStatusCB">SetMeetingAudioStatusCB</el-button>
    <el-button type="primary" round plain @click="setUserActiveAudioChangeCB">SetUserActiveAudioChangeCB</el-button>
    <el-button type="primary" round plain @click="joinVoip">JoinVoip</el-button>
    <el-button type="primary" round plain @click="leaveVoip">LeaveVoip</el-button>
    <div class="in-line">
      <el-select v-model="participants_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-checkbox v-model="allow_unmutebyself" label="Allowunmutebyself" @change="muteAudio"></el-checkbox>
      <el-button type="primary" round plain @click="muteAudio">MuteAudio</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="participants_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="unMuteAudio">UnMuteAudio</el-button>
    </div>
    <el-checkbox v-model="enable" label="EnablePlayChimeWhenEnterOrExit" @change="enablePlayChimeWhenEnterOrExit"></el-checkbox>
  </div>
  <div class="result">Result: {{result}}</div>
  <div class="result"> 
    <div class="result-item"> 
      <span class="title">onUserAudioStatusChange <el-button size="small" @click="onUserAudioStatusChange_options=[]">Clear</el-button></span> 
      <div class="callback-list">
        <span v-for="(item, index) in onUserAudioStatusChange_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
    <div class="result-item"> 
      <span class="title">onUserActiveAudioChange <el-button size="small" @click="onUserActiveAudioChange_options=[]">Clear</el-button></span> 
      <div class="callback-list">
        <span v-for="(item, index) in onUserActiveAudioChange_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, onMounted } from 'vue'
import { ZoomMeetingAudioStatus } from '../../../lib/settings.js'
import { getSDKResult } from '../../assets/ts/util'
const remote = window.require('@electron/remote')
const result = ref()
const onUserAudioStatusChange_options = ref<any[]>([])
const onUserActiveAudioChange_options = ref<any[]>([])

const onUserAudioStatusChange = (audioStatusList: any) => {
  console.log('onUserAudioStatusChange', audioStatusList)
  for (let item of audioStatusList) {
    let content = `${item.userid} - ${Object.keys(ZoomMeetingAudioStatus).find(k => ZoomMeetingAudioStatus[k] == item.audioStauts)}`
    onUserAudioStatusChange_options.value.push(content)
  }
}
const onUserActiveAudioChange = (lstActiveAudio: any) => {
  console.log('onUserActiveAudioChange', lstActiveAudio)
  onUserActiveAudioChange_options.value = lstActiveAudio
}
const zoomMeetingAudio = remote.app.zoomSdkModule.Meeting.GetMeetingAudio({onUserAudioStatusChange, onUserActiveAudioChange})
const zoomMeetingParticipants = remote.app.zoomSdkModule.Meeting.GetMeetingParticipantsCtrl()
const participantsList = ref<any[]>([])
const participants_value = ref()
const allow_unmutebyself = ref(true)
const enable = ref(true)

const setMeetingAudioStatusCB = () => {
  let ret = zoomMeetingAudio.MeetingAudio_SetMeetingAudioStatusCB(onUserAudioStatusChange)
  result.value = getSDKResult('MeetingAudio_SetMeetingAudioStatusCB', ret)
}

const setUserActiveAudioChangeCB = () => {
  let ret = zoomMeetingAudio.MeetingAudio_SetUserActiveAudioChangeCB(onUserActiveAudioChange)
  result.value = getSDKResult('MeetingAudio_SetUserActiveAudioChangeCB', ret)
}

const getParticipantsList = () => {
  let list = zoomMeetingParticipants.GetParticipantsList()
  result.value = getSDKResult('GetParticipantsList', list)
  participantsList.value = []
  let obj
  for (let item of list) {
    obj = zoomMeetingParticipants.GetUserInfoByUserID(item.userid)
    participantsList.value.push(obj)
  }
  if (participantsList.value.length == 0) {
    participants_value.value = ''
  } else {
    participants_value.value = obj.userID
  }
}

const muteAudio = () => {
  let param = {userid: participants_value.value, allowunmutebyself: allow_unmutebyself.value}
  let ret = zoomMeetingAudio.MeetingAudio_MuteAudio(param)
  result.value = getSDKResult('MeetingAudio_MuteAudio', ret, param)
}

const unMuteAudio = () => {
  let param = {userid: participants_value.value}
  let ret = zoomMeetingAudio.MeetingAudio_UnMuteAudio(param)
  result.value = getSDKResult('MeetingAudio_UnMuteAudio', ret, param)
}

const joinVoip = () => {
  let ret = zoomMeetingAudio.MeetingAudio_JoinVoip()
  result.value = getSDKResult('MeetingAudio_JoinVoip', ret)
}

const leaveVoip = () => {
  let ret = zoomMeetingAudio.MeetingAudio_LeaveVoip()
  result.value = getSDKResult('MeetingAudio_LeaveVoip', ret)
}

const enablePlayChimeWhenEnterOrExit = () => {
  let param = {bEnable: enable.value}
  let ret = zoomMeetingAudio.MeetingAudio_EnablePlayChimeWhenEnterOrExit(param)
  result.value = getSDKResult('MeetingAudio_EnablePlayChimeWhenEnterOrExit', ret, param)
}

onMounted(() => {
  getParticipantsList()
})
</script>