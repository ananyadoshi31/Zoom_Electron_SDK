<template>
  <div class="meeting">
    <el-button type="primary" round plain @click="setMeetingStatisticsWarningNotificationCB">SetMeetingStatisticsWarningNotificationCB</el-button>
    <el-button type="primary" round plain @click="setMeetingParameterNotificationCB">SetMeetingParameterNotificationCB</el-button>
    <el-button type="primary" round plain @click="leaveMeeting">LeaveMeeting</el-button>
    <el-button type="primary" round plain @click="lockMeeting">Lock_Meeting</el-button>
    <el-button type="primary" round plain @click="unLockMeeting">Un_lock_Meeting</el-button>
    <el-button type="primary" round plain @click="getSharingConnQuality">GetSharingConnQuality</el-button>
    <el-button type="primary" round plain @click="getVideoConnQuality">GetVideoConnQuality</el-button>
    <el-button type="primary" round plain @click="getAudioConnQuality">GetAudioConnQuality</el-button>
  </div>
  <div class="result">Result: {{result}}</div>
  <div class="result"> 
    <div class="result-item"> 
      <span class="title">meetingstatuscb <el-button size="small" @click="meetingstatuscb_options=[]">Clear</el-button></span>
      <div class="callback-list">
        <span v-for="(item, index) in meetingstatuscb_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
    <div class="result-item"> 
      <span class="title">onMeetingStatisticsWarningNotification <el-button size="small" @click="onMeetingStatisticsWarningNotification_options=[]">Clear</el-button></span> 
      <div class="callback-list">
        <span v-for="(item, index) in onMeetingStatisticsWarningNotification_options" :key="index">{{index}} : {{item}}</span>
      </div>
    </div>
    <div class="result-item"> 
      <span class="title">onMeetingParameterNotification <el-button size="small" @click="onMeetingParameterNotification_options=[]">Clear</el-button></span>
      <div class="callback-list">
        <span v-for="(item, index) in onMeetingParameterNotification_options" :key="index">{{index}} : {{item}}</span>
      </div> 
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, onMounted, onBeforeUnmount } from 'vue'
import { ZoomMeetingStatus, StatisticsWarningType } from '../../../lib/settings.js'
import { getSDKResult } from '../../assets/ts/util'
const remote = window.require('@electron/remote')
const result = ref()
const meetingstatuscb_options = ref<any[]>([])
const onMeetingStatisticsWarningNotification_options = ref<any[]>([])
const onMeetingParameterNotification_options = ref<any[]>([])

const meetingstatuscb = (meetingStatus: string, result: string) => {
  let statusContent = Object.keys(ZoomMeetingStatus).find(k => ZoomMeetingStatus[k] == meetingStatus)
  console.log('meetingstatuscb', meetingStatus, result, statusContent)
  meetingstatuscb_options.value.push(statusContent)
}
const onMeetingStatisticsWarningNotification = (type: number) => {
  let content = Object.keys(StatisticsWarningType).find(k => StatisticsWarningType[k] == type)
  console.log('onMeetingStatisticsWarningNotification', type, content)
  onMeetingStatisticsWarningNotification_options.value.push(content)
}
const onMeetingParameterNotification = (meeting_param: any) => {
  console.log('onMeetingParameterNotification', meeting_param)
  meeting_param.meeting_number = meeting_param.meeting_number + ''
  let content = JSON.stringify(meeting_param)
  onMeetingParameterNotification_options.value.push(content)
}
const zoomMeeting = remote.app.zoomSdkModule.Meeting

const setMeetingStatusCB = () => {
  let ret = zoomMeeting.SetMeetingStatusCB(meetingstatuscb)
  result.value = getSDKResult('SetMeetingStatusCB', ret)
}

const setMeetingStatisticsWarningNotificationCB = () => {
  let ret = zoomMeeting.SetMeetingStatisticsWarningNotificationCB(onMeetingStatisticsWarningNotification)
  result.value = getSDKResult('SetMeetingStatisticsWarningNotificationCB', ret)
}

const setMeetingParameterNotificationCB = () => {
  let ret = zoomMeeting.SetMeetingParameterNotificationCB(onMeetingParameterNotification)
  result.value = getSDKResult('SetMeetingParameterNotificationCB', ret)
}

const leaveMeeting = () => {
  let ret = zoomMeeting.LeaveMeeting()
  result.value = getSDKResult('LeaveMeeting', ret)
}

const lockMeeting = () => {
  let ret = zoomMeeting.Lock_Meeting()
  result.value = getSDKResult('Lock_Meeting', ret)
}

const unLockMeeting = () => {
  let ret = zoomMeeting.Un_lock_Meeting()
  result.value = getSDKResult('Un_lock_Meeting', ret)
}

const getSharingConnQuality = () => {
  let ret = zoomMeeting.GetSharingConnQuality()
  result.value = `GetSharingConnQuality - ${ret}`
}

const getVideoConnQuality = () => {
  let ret = zoomMeeting.GetVideoConnQuality()
  result.value = `GetVideoConnQuality - ${ret}`
}

const getAudioConnQuality = () => {
  let ret = zoomMeeting.GetAudioConnQuality()
  result.value = `GetAudioConnQuality - ${ret}`
}

const handleMsg = (msg: any) => {
  if (msg.type == 'message') {
    let {meetingStatus, result} = msg.data
    meetingstatuscb(meetingStatus, result)
  }
}

onMounted(() => {
  setMeetingStatisticsWarningNotificationCB()
  setMeetingParameterNotificationCB()
  window.addEventListener('message', msg => handleMsg(msg))
})

onBeforeUnmount(() => {
  window.removeEventListener('message', handleMsg)
})
</script>