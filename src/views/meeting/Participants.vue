<template>
  <div class="meeting">
    <el-button type="primary" round plain @click="setMeetingUserJoinCB">SetMeetingUserJoinCB</el-button>
    <el-button type="primary" round plain @click="setMeetingUserLeftCB">SetMeetingUserLeftCB</el-button>
    <el-button type="primary" round plain @click="setMeetingHostChangeCB">SetMeetingHostChangeCB</el-button>
    <div class="in-line">
      <el-select v-model="participants_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="getUserInfoByUserID">GetUserInfoByUserID</el-button>
    </div>
  </div>
  <el-table :data="participantsList" stripe style="width: 100%">
    <el-table-column prop="userName" label="userName" :show-overflow-tooltip="true"></el-table-column>
    <el-table-column prop="userID" label="userID"></el-table-column>
    <el-table-column prop="isHost" label="isHost"></el-table-column>
    <el-table-column prop="isMySelf" label="isMySelf"></el-table-column>
    <el-table-column prop="isVideoOn" label="isVideoOn"></el-table-column>
    <el-table-column prop="isAudioMuted" label="isAudioMuted"></el-table-column>
  </el-table>
  <div class="result">Result: {{result}}</div>
  <div class="result"> 
    <div class="result-item"> 
      <span class="title">meetinguserjoincb <el-button size="small" @click="meetinguserjoincb_options=[]">Clear</el-button></span> 
      <div class="callback-list">
        <span v-for="(item, index) in meetinguserjoincb_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
    <div class="result-item"> 
      <span class="title">meetinguserleftcb <el-button size="small" @click="meetinguserleftcb_options=[]">Clear</el-button></span> 
      <div class="callback-list">
        <span v-for="(item, index) in meetinguserleftcb_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
    <div class="result-item"> 
      <span class="title">meetinghostchangecb <el-button size="small" @click="meetinghostchangecb_options=[]">Clear</el-button></span> 
      <div class="callback-list">
        <span v-for="(item, index) in meetinghostchangecb_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, onMounted } from 'vue'
import { getSDKResult } from '../../assets/ts/util'
const remote = window.require('@electron/remote')
const result = ref()
const meetinguserjoincb_options = ref<any[]>([])
const meetinguserleftcb_options = ref<any[]>([])
const meetinghostchangecb_options = ref<any[]>([])

const meetinguserjoincb = (strUserList: any, lstUserID: number) => {
  console.log('meetinguserjoincb', strUserList, lstUserID)
  meetinguserjoincb_options.value = strUserList
}
const meetinguserleftcb = (strUserList: any, lstUserID: number) => {
  console.log('meetinguserleftcb', strUserList, lstUserID)
  meetinguserleftcb_options.value = strUserList
}
const meetinghostchangecb = (userid: number) => {
  console.log('meetinghostchangecb', userid)
  meetinghostchangecb_options.value.push(userid)
}
const zoomMeetingParticipants = remote.app.zoomSdkModule.Meeting.GetMeetingParticipantsCtrl({meetinguserjoincb, meetinguserleftcb, meetinghostchangecb})
const participantsList = ref<any[]>([])
const participants_value = ref()

const setMeetingUserJoinCB = () => {
  let ret = zoomMeetingParticipants.SetMeetingUserJoinCB(meetinguserjoincb)
  result.value = getSDKResult('SetMeetingUserJoinCB', ret)
}

const setMeetingUserLeftCB = () => {
  let ret = zoomMeetingParticipants.SetMeetingUserLeftCB(meetinguserleftcb)
  result.value = getSDKResult('SetMeetingUserLeftCB', ret)
}

const setMeetingHostChangeCB = () => {
  let ret = zoomMeetingParticipants.SetMeetingHostChangeCB(meetinghostchangecb)
  result.value = getSDKResult('SetMeetingHostChangeCB', ret)
}

const getParticipantsList = () => {
  let list = zoomMeetingParticipants.GetParticipantsList()
  console.log(list)
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

const getUserInfoByUserID = () => {
  let param = participants_value.value
  let ret = zoomMeetingParticipants.GetUserInfoByUserID(param)
  result.value = getSDKResult('GetUserInfoByUserID', ret, param)
}

onMounted(() => {
  getParticipantsList()
})
</script>