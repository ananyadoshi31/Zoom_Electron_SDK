<template>
  <div class="meeting">
    <el-button type="primary" round plain @click="setonRecording2MP4DoneCB">SetonRecording2MP4DoneCB</el-button>
    <el-button type="primary" round plain @click="setonRecording2MP4ProcessingCB">SetonRecording2MP4ProcessingCB</el-button>
    <el-button type="primary" round plain @click="setonRecordingStatusCB">SetonRecordingStatusCB</el-button>
    <el-button type="primary" round plain @click="setonCloudRecordingStatusCB">SetonCloudRecordingStatusCB</el-button>
    <el-button type="primary" round plain @click="setonRecordPriviligeChangedCB">SetonRecordPriviligeChangedCB</el-button>
    <el-button type="primary" round plain @click="startRecording">StartRecording</el-button>
    <el-button type="primary" round plain @click="stopRecording">StopRecording</el-button>
    <el-button type="primary" round plain @click="canAllowDisAllowLocalRecording">CanAllowDisAllowLocalRecording</el-button>
    <el-button type="primary" round plain @click="startCloudRecording">StartCloudRecording</el-button>
    <el-button type="primary" round plain @click="stopCloudRecording">StopCloudRecording</el-button>
    <div class="in-line">
      <el-select v-model="participants_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-checkbox v-model="cloud_recording" label="Cloud Recording" @change="canStartRecording"></el-checkbox>
      <el-button type="primary" round plain @click="canStartRecording">CanStartRecording</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="participants_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="isSupportLocalRecording">IsSupportLocalRecording</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="participants_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="allowLocalRecording">AllowLocalRecording</el-button>
    </div>
    <div class="in-line">
      <el-select v-model="participants_value" placeholder="Select" @focus="getParticipantsList">
        <el-option v-for="(item, index) in participantsList" :key="index" :label="item.userName" :value="item.userID"></el-option>
      </el-select>
      <el-button type="primary" round plain @click="disAllowLocalRecording">DisAllowLocalRecording</el-button>
    </div>
  </div>
  <div>
    <div class="result">Result: {{result}}</div>
    <div class="result"> 
      <div class="result-item"> 
        <span class="title">onRecording2MP4Done <el-button size="small" @click="onRecording2MP4Done_options=[]">Clear</el-button></span> 
        <div class="callback-list">
          <span v-for="(item, index) in onRecording2MP4Done_options" :key="index">{{index}} : {{item}}</span>
        </div>
      </div>
      <div class="result-item"> 
        <span class="title">onRecording2MP4Processing <el-button size="small" @click="onRecording2MP4Processing_options=[]">Clear</el-button></span> 
        <div class="callback-list">
          <span v-for="(item, index) in onRecording2MP4Processing_options" :key="index">{{index}} : {{item}}</span>
        </div>
      </div>
      <div class="result-item"> 
        <span class="title">onRecordingStatus <el-button size="small" @click="onRecordingStatus_options=[]">Clear</el-button></span> 
        <div class="callback-list">
          <span v-for="(item, index) in onRecordingStatus_options" :key="index">{{index}} : {{item}}</span>
        </div>
      </div>
      <div class="result-item"> 
        <span class="title">onCloudRecordingStatus <el-button size="small" @click="onCloudRecordingStatus_options=[]">Clear</el-button></span> 
        <div class="callback-list">
          <span v-for="(item, index) in onCloudRecordingStatus_options" :key="index">{{index}} : {{item}}</span>
        </div>
      </div>
      <div class="result-item"> 
        <span class="title">onRecordPriviligeChanged <el-button size="small" @click="onRecordPriviligeChanged_options=[]">Clear</el-button></span> 
        <div class="callback-list">
          <span v-for="(item, index) in onRecordPriviligeChanged_options" :key="index">{{index}} : {{item}}</span>
        </div>  
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, onMounted } from 'vue'
import { RecordingStatus } from '../../../lib/settings.js'
import { getSDKResult } from '../../assets/ts/util'
const remote = window.require('@electron/remote')
const result = ref()
const clientHeight = ref((window.innerHeight - 365) + 'px')
const onRecording2MP4Done_options = ref<any[]>([])
const onRecording2MP4Processing_options = ref<any[]>([])
const onRecordingStatus_options = ref<any[]>([])
const onCloudRecordingStatus_options = ref<any[]>([])
const onRecordPriviligeChanged_options = ref<any[]>([])

const onRecording2MP4Done = (success: boolean, result: string, path: string) => {
  console.log('onRecording2MP4Done', success, result, path)
  let content = `${success} - ${result} - ${path}`
  onRecording2MP4Done_options.value.push(content)
}
const onRecording2MP4Processing = (percentage: string) => {
  console.log('onRecording2MP4Processing', percentage)
  onRecording2MP4Processing_options.value.push(percentage)
}
const onRecordingStatus = (status: string) => {
  let statusContent = Object.keys(RecordingStatus).find(k => RecordingStatus[k] == status)
  console.log('onRecordingStatus', status, statusContent)
  onRecordingStatus_options.value.push(statusContent)
}
const onCloudRecordingStatus = (status: string) => {
  let statusContent = Object.keys(RecordingStatus).find(k => RecordingStatus[k] == status)
  console.log('onCloudRecordingStatus', status, statusContent)
  onCloudRecordingStatus_options.value.push(statusContent)
}
const onRecordPriviligeChanged = (canRec: boolean) => {
  console.log('onRecordPriviligeChanged', canRec)
  onRecordPriviligeChanged_options.value.push(canRec)
}
const zoomMeetingRecording = remote.app.zoomSdkModule.Meeting.GetMeetingRecording({onRecording2MP4Done, onRecording2MP4Processing, onRecordingStatus, onCloudRecordingStatus, onRecordPriviligeChanged})
const zoomMeetingParticipants = remote.app.zoomSdkModule.Meeting.GetMeetingParticipantsCtrl()
const participantsList = ref<any[]>([])
const participants_value = ref()
const cloud_recording = ref(true)
const enable = ref(true)

const setonRecording2MP4DoneCB = () => {
  let ret = zoomMeetingRecording.SetonRecording2MP4DoneCB(onRecording2MP4Done)
  result.value = getSDKResult('SetonRecording2MP4DoneCB', ret)
}

const setonRecording2MP4ProcessingCB = () => {
  let ret = zoomMeetingRecording.SetonRecording2MP4ProcessingCB(onRecording2MP4Processing)
  result.value = getSDKResult('SetonRecording2MP4ProcessingCB', ret)
}

const setonRecordingStatusCB = () => {
  let ret = zoomMeetingRecording.SetonRecordingStatusCB(onRecordingStatus)
  result.value = getSDKResult('SetonRecordingStatusCB', ret)
}

const setonCloudRecordingStatusCB = () => {
  let ret = zoomMeetingRecording.SetonCloudRecordingStatusCB(onCloudRecordingStatus)
  result.value = getSDKResult('SetonRecordingStatusCB', ret)
}

const setonRecordPriviligeChangedCB = () => {
  let ret = zoomMeetingRecording.SetonRecordPriviligeChangedCB(onRecordPriviligeChanged)
  result.value = getSDKResult('SetonRecordPriviligeChangedCB', ret)
}

const startRecording = () => {
  let ret = zoomMeetingRecording.StartRecording()
  result.value = getSDKResult('StartRecording', ret)
}

const stopRecording = () => {
  let ret = zoomMeetingRecording.StopRecording()
  result.value = getSDKResult('StopRecording', ret)
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

const canStartRecording = () => {
  let param = {userid: participants_value.value, cloud_recording: cloud_recording.value}
  let ret = zoomMeetingRecording.CanStartRecording(param)
  result.value = getSDKResult('CanStartRecording', ret, param)
}

const canAllowDisAllowLocalRecording = () => {
  let ret = zoomMeetingRecording.CanAllowDisAllowLocalRecording()
  result.value = getSDKResult('CanAllowDisAllowLocalRecording', ret)
}

const startCloudRecording = () => {
  let ret = zoomMeetingRecording.StartCloudRecording()
  result.value = getSDKResult('StartCloudRecording', ret)
}

const stopCloudRecording = () => {
  let ret = zoomMeetingRecording.StopCloudRecording()
  result.value = getSDKResult('StopCloudRecording', ret)
}

const isSupportLocalRecording = () => {
  let param = {userid: participants_value.value}
  let ret = zoomMeetingRecording.IsSupportLocalRecording(param)
  result.value = getSDKResult('IsSupportLocalRecording', ret, param)
}

const allowLocalRecording = () => {
  let param = {userid: participants_value.value}
  let ret = zoomMeetingRecording.AllowLocalRecording(param)
  result.value = getSDKResult('AllowLocalRecording', ret, param)
}

const disAllowLocalRecording = () => {
  let param = {userid: participants_value.value}
  let ret = zoomMeetingRecording.DisAllowLocalRecording(param)
  result.value = getSDKResult('DisAllowLocalRecording', ret, param)
}

onMounted(() => {
  getParticipantsList()
  window.addEventListener('resize', ()=>{
    clientHeight.value = (window.innerHeight - 365) + 'px'
  })
})
</script>
<style scoped lang="scss">
.meeting {
  height: v-bind(clientHeight);
}
</style>