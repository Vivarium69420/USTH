from scipy.io import wavfile
import numpy as np
import matplotlib.pyplot as plt
from scipy import signal as sig

# Read the wav file (mono)
fs_no, data_no = wavfile.read('noNoise.wav')
fs_low, data_low = wavfile.read('lowNoise.wav')
fs_medium, data_medium = wavfile.read('mediumNoise.wav')
fs_high, data_high = wavfile.read('highNoise.wav')

# Convert to mono
data_no = data_no[:,0]
data_low = data_low[:,0]
data_medium = data_medium[:,0]
data_high = data_high[:,0]

# # Plot the diffrent noise levels in the time domain and in same plot in a row of sublots
# plt.figure(1)
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

# # Plot the diffrent noise levels in the frequency domain using signal.freqz and in same plot in a row of sublots
# plt.figure(2)
# plt.subplot(411)
# plt.plot(sig.freqz(data_no)[0], 20 * np.log10(abs(sig.freqz(data_no)[1])), color="C0", label='No noise')
# plt.title('No noise')
# plt.legend()
# plt.subplot(412)
# plt.plot(sig.freqz(data_low)[0], 20 * np.log10(abs(sig.freqz(data_low)[1])), color="C1", label='Low nosie')
# plt.title('Low noise')
# plt.legend()
# plt.subplot(413)
# plt.plot(sig.freqz(data_medium)[0], 20 * np.log10(abs(sig.freqz(data_medium)[1])), color="C2", label='Medium noise')
# plt.title('Medium noise')
# plt.legend()
# plt.subplot(414)
# plt.plot(sig.freqz(data_high)[0], 20 * np.log10(abs(sig.freqz(data_high)[1])), color="C3", label='High noise')
# plt.title('High noise')
# plt.legend()
# plt.tight_layout()
# plt.show()



# apply the blackman window to the data
data_no_blackman = data_no * np.blackman(len(data_no))
data_low_blackman = data_low * np.blackman(len(data_low))
data_medium_blackman = data_medium * np.blackman(len(data_medium))
data_high_blackman = data_high * np.blackman(len(data_high))

# # Plot the diffrent noise levels in the time domain and in same plot in a row of sublots
# plt.figure(2)
# plt.subplot(411)
# plt.plot(data_no_blackman)
# plt.title('No noise with blackman window')
# plt.subplot(412)
# plt.plot(data_low_blackman)
# plt.title('Low noise with blackman window')
# plt.subplot(413)
# plt.plot(data_medium_blackman)
# plt.title('Medium noise with blackman window')
# plt.subplot(414)
# plt.plot(data_high_blackman)
# plt.title('High noise with blackman window')
# plt.tight_layout()
# plt.show()

# # Plot the diffrent noise levels after filter in the frequency domain using signal.freqz and in same plot in a row of sublots
# plt.figure(3)
# plt.subplot(411)
# plt.plot(sig.freqz(data_no_blackman)[0], 20 * np.log10(abs(sig.freqz(data_no_blackman)[1])), color="C0", label='No noise')
# plt.title('No noise with blackman window')
# plt.legend()
# plt.subplot(412)
# plt.plot(sig.freqz(data_low_blackman)[0], 20 * np.log10(abs(sig.freqz(data_low_blackman)[1])), color="C1", label='Low nosie')
# plt.title('Low noise with blackman window')
# plt.legend()
# plt.subplot(413)
# plt.plot(sig.freqz(data_medium_blackman)[0], 20 * np.log10(abs(sig.freqz(data_medium_blackman)[1])), color="C2", label='Medium noise')
# plt.title('Medium noise with blackman window')
# plt.legend()
# plt.subplot(414)
# plt.plot(sig.freqz(data_high_blackman)[0], 20 * np.log10(abs(sig.freqz(data_high_blackman)[1])), color="C3", label='High noise')
# plt.title('High noise with blackman window')
# plt.legend()
# plt.tight_layout()
# plt.show()

# # Plot the diffrent noise levels after filter vs before the filter overlaping in the time domain and in same plot in a row of sublots
# plt.figure(4)
# plt.subplot(411)
# plt.plot(data_no, label='Before')
# plt.plot(data_no_blackman, label='After')
# plt.title('No noise')
# plt.legend()
# plt.subplot(412)
# plt.plot(data_low, label='Before')
# plt.plot(data_low_blackman, label='After')
# plt.title('Low noise')
# plt.legend()
# plt.subplot(413)
# plt.plot(data_medium, label='Before')
# plt.plot(data_medium_blackman, label='After')
# plt.title('Medium noise')
# plt.legend()
# plt.subplot(414)
# plt.plot(data_high, label='Before')
# plt.plot(data_high_blackman, label='After')
# plt.title('High noise')
# plt.legend()
# plt.tight_layout()
# plt.show()


# Plot the diffrent noise levels after filter vs before the filter overlaping in the frequency domain and in same plot in a row of sublots
plt.figure(5)
plt.subplot(411)
plt.plot(sig.freqz(data_no)[0], 20 * np.log10(abs(sig.freqz(data_no)[1])), color="C0", label='Before')
plt.plot(sig.freqz(data_no_blackman)[0], 20 * np.log10(abs(sig.freqz(data_no_blackman)[1])), color="C1", label='After')
plt.title('No noise')
plt.legend()
plt.subplot(412)
plt.plot(sig.freqz(data_low)[0], 20 * np.log10(abs(sig.freqz(data_low)[1])), color="C0", label='Before')
plt.plot(sig.freqz(data_low_blackman)[0], 20 * np.log10(abs(sig.freqz(data_low_blackman)[1])), color="C1", label='After')
plt.title('Low noise')
plt.legend()
plt.subplot(413)
plt.plot(sig.freqz(data_medium)[0], 20 * np.log10(abs(sig.freqz(data_medium)[1])), color="C0", label='Before')
plt.plot(sig.freqz(data_medium_blackman)[0], 20 * np.log10(abs(sig.freqz(data_medium_blackman)[1])), color="C1", label='After')
plt.title('Medium noise')
plt.legend()
plt.subplot(414)
plt.plot(sig.freqz(data_high)[0], 20 * np.log10(abs(sig.freqz(data_high)[1])), color="C0", label='Before')
plt.plot(sig.freqz(data_high_blackman)[0], 20 * np.log10(abs(sig.freqz(data_high_blackman)[1])), color="C1", label='After')
plt.title('High noise')
plt.legend()
plt.tight_layout()
plt.show()


