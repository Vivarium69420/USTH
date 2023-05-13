from scipy.io import wavfile
import numpy as np
import matplotlib.pyplot as plt

# Read the wav file (mono)
fs_no, data_no = wavfile.read('sound_files/noNoise.wav')
fs_low, data_low = wavfile.read('sound_files/lowNoise.wav')
fs_medium, data_medium = wavfile.read('sound_files/mediumNoise.wav')
fs_high, data_high = wavfile.read('sound_files/highNoise.wav')

# Convert to mono
data_no = data_no[:,0]
data_low = data_low[:,0]
data_medium = data_medium[:,0]
data_high = data_high[:,0]

# # Plot the diffrent noise levels in the time domain and in same plot in a row of sublots
# plt.figure("Fig.12: Raw sound data in time domain")
# plt.subplot(411)
# plt.plot(data_no)
# plt.title('No noise')
# plt.subplot(412)
# plt.plot(data_low)
# plt.title('Low noise')
# plt.subplot(413)
# plt.plot(data_medium)
# plt.title('Medium noise')
# plt.subplot(414)
# plt.plot(data_high)
# plt.title('High noise')
# plt.tight_layout()
# plt.show()

# # Plot the diffrent noise levels in the frequency domain using fft and in same plot in a row of sublots first 4000 samples
# plt.figure("Fig.13: Raw sound data first 4000 samples in frequency domain")
# plt.subplot(411)
# plt.plot(np.fft.fft(data_no)[0:4000], color="C0", label='No noise')
# plt.title('No noise')
# plt.legend()
# plt.subplot(412)
# plt.plot(np.fft.fft(data_low)[0:4000], color="C1", label='Low nosie')
# plt.title('Low noise')
# plt.legend()
# plt.subplot(413)
# plt.plot(np.fft.fft(data_medium)[0:4000], color="C2", label='Medium noise')
# plt.title('Medium noise')
# plt.legend()
# plt.subplot(414)
# plt.plot(np.fft.fft(data_high)[0:4000], color="C3", label='High noise')
# plt.title('High noise')  
# plt.legend()
# plt.tight_layout()
# plt.show()


# apply the blackman window to the data
data_no_blackman = data_no * np.blackman(len(data_no))
data_low_blackman = data_low * np.blackman(len(data_low))
data_medium_blackman = data_medium * np.blackman(len(data_medium))
data_high_blackman = data_high * np.blackman(len(data_high))

# Plot the diffrent noise levels in the time domain and in same plot in a row of sublots
plt.figure("Fig.14: Filtered data in time domain with Blackman window")
plt.subplot(411)
plt.plot(data_no_blackman)
plt.title('No noise with blackman window')
plt.subplot(412)
plt.plot(data_low_blackman)
plt.title('Low noise with blackman window')
plt.subplot(413)
plt.plot(data_medium_blackman)
plt.title('Medium noise with blackman window')
plt.subplot(414)
plt.plot(data_high_blackman)
plt.title('High noise with blackman window')
plt.tight_layout()
plt.show()

# Plot the diffrent noise levels after filter vs before the filter overlaping in the time domain and in same plot in a row of sublots
plt.figure(4)
plt.subplot(411)
plt.plot(data_no)
plt.plot(data_no_blackman)
plt.title('No noise')
plt.legend()
plt.subplot(412)
plt.plot(data_low)
plt.plot(data_low_blackman)
plt.title('Low noise')
plt.legend()
plt.subplot(413)
plt.plot(data_medium)
plt.plot(data_medium_blackman)
plt.title('Medium noise')
plt.legend()
plt.subplot(414)
plt.plot(data_high)
plt.plot(data_high_blackman)
plt.title('High noise')
plt.legend()
plt.tight_layout()
plt.show()

# write the filtered data to a wav file 
wavfile.write('noNoise_blackman.wav', fs_no, data_no_blackman)
wavfile.write('lowNoise_blackman.wav', fs_low, data_low_blackman)
wavfile.write('mediumNoise_blackman.wav', fs_medium, data_medium_blackman)
wavfile.write('highNoise_blackman.wav', fs_high, data_high_blackman)
