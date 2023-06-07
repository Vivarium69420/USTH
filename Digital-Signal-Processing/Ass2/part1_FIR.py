import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as sig

Input_1kHz_15kHz_raw = [

    +0.0000000000, +0.5924659585, -0.0947343455, +0.1913417162, +
    1.0000000000, +0.4174197128, +0.3535533906, +1.2552931065,
    +0.8660254038, +0.4619397663, +1.3194792169, +1.1827865776, +
    0.5000000000, +1.1827865776, +1.3194792169, +0.4619397663,
    +0.8660254038, +1.2552931065, +0.3535533906, +0.4174197128, +
    1.0000000000, +0.1913417162, -0.0947343455, +0.5924659585,
    -0.0000000000, -0.5924659585, +0.0947343455, -0.1913417162, -
    1.0000000000, -0.4174197128, -0.3535533906, -1.2552931065,
    -0.8660254038, -0.4619397663, -1.3194792169, -1.1827865776, -
    0.5000000000, -1.1827865776, -1.3194792169, -0.4619397663,
    -0.8660254038, -1.2552931065, -0.3535533906, -0.4174197128, -
    1.0000000000, -0.1913417162, +0.0947343455, -0.5924659585,
    +0.0000000000, +0.5924659585, -0.0947343455, +0.1913417162, +
    1.0000000000, +0.4174197128, +0.3535533906, +1.2552931065,
    +0.8660254038, +0.4619397663, +1.3194792169, +1.1827865776, +
    0.5000000000, +1.1827865776, +1.3194792169, +0.4619397663,
    +0.8660254038, +1.2552931065, +0.3535533906, +0.4174197128, +
    1.0000000000, +0.1913417162, -0.0947343455, +0.5924659585,
    +0.0000000000, -0.5924659585, +0.0947343455, -0.1913417162, -
    1.0000000000, -0.4174197128, -0.3535533906, -1.2552931065,
    -0.8660254038, -0.4619397663, -1.3194792169, -1.1827865776, -
    0.5000000000, -1.1827865776, -1.3194792169, -0.4619397663,
    -0.8660254038, -1.2552931065, -0.3535533906, -0.4174197128, -
    1.0000000000, -0.1913417162, +0.0947343455, -0.5924659585,
    +0.0000000000, +0.5924659585, -0.0947343455, +0.1913417162, +
    1.0000000000, +0.4174197128, +0.3535533906, +1.2552931065,
    +0.8660254038, +0.4619397663, +1.3194792169, +1.1827865776, +
    0.5000000000, +1.1827865776, +1.3194792169, +0.4619397663,
    +0.8660254038, +1.2552931065, +0.3535533906, +0.4174197128, +
    1.0000000000, +0.1913417162, -0.0947343455, +0.5924659585,
    +0.0000000000, -0.5924659585, +0.0947343455, -0.1913417162, -
    1.0000000000, -0.4174197128, -0.3535533906, -1.2552931065,
    -0.8660254038, -0.4619397663, -1.3194792169, -1.1827865776, -
    0.5000000000, -1.1827865776, -1.3194792169, -0.4619397663,
    -0.8660254038, -1.2552931065, -0.3535533906, -0.4174197128, -
    1.0000000000, -0.1913417162, +0.0947343455, -0.5924659585,
    -0.0000000000, +0.5924659585, -0.0947343455, +0.1913417162, +
    1.0000000000, +0.4174197128, +0.3535533906, +1.2552931065,
    +0.8660254038, +0.4619397663, +1.3194792169, +1.1827865776, +
    0.5000000000, +1.1827865776, +1.3194792169, +0.4619397663,
    +0.8660254038, +1.2552931065, +0.3535533906, +0.4174197128, +
    1.0000000000, +0.1913417162, -0.0947343455, +0.5924659585,
    -0.0000000000, -0.5924659585, +0.0947343455, -0.1913417162, -
    1.0000000000, -0.4174197128, -0.3535533906, -1.2552931065,
    -0.8660254038, -0.4619397663, -1.3194792169, -1.1827865776, -
    0.5000000000, -1.1827865776, -1.3194792169, -0.4619397663,
    -0.8660254038, -1.2552931065, -0.3535533906, -0.4174197128, -
    1.0000000000, -0.1913417162, +0.0947343455, -0.5924659585,
    +0.0000000000, +0.5924659585, -0.0947343455, +0.1913417162, +
    1.0000000000, +0.4174197128, +0.3535533906, +1.2552931065,
    +0.8660254038, +0.4619397663, +1.3194792169, +1.1827865776, +
    0.5000000000, +1.1827865776, +1.3194792169, +0.4619397663,
    +0.8660254038, +1.2552931065, +0.3535533906, +0.4174197128, +
    1.0000000000, +0.1913417162, -0.0947343455, +0.5924659585,
    +0.0000000000, -0.5924659585, +0.0947343455, -0.1913417162, -
    1.0000000000, -0.4174197128, -0.3535533906, -1.2552931065,
    -0.8660254038, -0.4619397663, -1.3194792169, -1.1827865776, -
    0.5000000000, -1.1827865776, -1.3194792169, -0.4619397663,
    -0.8660254038, -1.2552931065, -0.3535533906, -0.4174197128, -
    1.0000000000, -0.1913417162, +0.0947343455, -0.5924659585,
    -0.0000000000, +0.5924659585, -0.0947343455, +0.1913417162, +
    1.0000000000, +0.4174197128, +0.3535533906, +1.2552931065,
    +0.8660254038, +0.4619397663, +1.3194792169, +1.1827865776, +
    0.5000000000, +1.1827865776, +1.3194792169, +0.4619397663,
    +0.8660254038, +1.2552931065, +0.3535533906, +0.4174197128, +
    1.0000000000, +0.1913417162, -0.0947343455, +0.5924659585,
    +0.0000000000, -0.5924659585, +0.0947343455, -0.1913417162, -
    1.0000000000, -0.4174197128, -0.3535533906, -1.2552931065,
    -0.8660254038, -0.4619397663, -1.3194792169, -1.1827865776, -
    0.5000000000, -1.1827865776, -1.3194792169, -0.4619397663,
    -0.8660254038, -1.2552931065, -0.3535533906, -0.4174197128, -
    1.0000000000, -0.1913417162, +0.0947343455, -0.5924659585,
    -0.0000000000, +0.5924659585, -0.0947343455, +0.1913417162, +
    1.0000000000, +0.4174197128, +0.3535533906, +1.2552931065,
    +0.8660254038, +0.4619397663, +1.3194792169, +1.1827865776, +
    0.5000000000, +1.1827865776, +1.3194792169, +0.4619397663,
    +0.8660254038, +1.2552931065, +0.3535533906, +0.4174197128, +
    1.0000000000, +0.1913417162, -0.0947343455, +0.5924659585,
    +0.0000000000, -0.5924659585, +0.0947343455, -0.1913417162, -
    1.0000000000, -0.4174197128, -0.3535533906, -1.2552931065,
]

Input_1kHz_15kHz = np.array(Input_1kHz_15kHz_raw)

# Create a Bartlett, Hamming, Blackman filter using the scipy.signal.bartlett() function
bartlett_filter = sig.bartlett(51)
hamming_filter = sig.hamming(51)
blackman_filter = sig.blackman(51)

# # Plot the filter coefficients in the time domain
# plt.figure("Fig.1: FIR Comparison of Bartlett, Hamming, Blackman filters in Time Domain", figsize=(10, 10))
# plt.suptitle('Fig.1: FIR Comparison of Bartlett, Hamming, Blackman filters in Time Domain')
# plt.plot(bartlett_filter, color="C0", label='Bartlett filter')
# plt.plot(hamming_filter, color="C1", label='Hamming filter')
# plt.plot(blackman_filter, color="C2", label='Blackman filter')
# plt.xlabel('Sample')
# plt.ylabel('Amplitude')
# plt.legend(fontsize="larger")
# plt.show()

# # Plot the each filter's frequency response using the scipy.signal.freqz() function in dB scale and in rows of 3 subplots
# plt.figure("Fig.2: FIR Comparison of Bartlett, Hamming, Blackman filters in Frequency Domain", figsize=(10, 10))
# plt.suptitle('Fig.2: FIR Comparison of Bartlett, Hamming, Blackman filters in Frequency Domain')
# plt.subplot(3, 1, 1)
# plt.plot(sig.freqz(bartlett_filter)[0], 20 * np.log10(abs(sig.freqz(bartlett_filter)[1])), color="C0", label='Bartlett filter')
# plt.ylabel('Amplitude [dB]')
# plt.xlabel('Frequency [rad/sample]')
# plt.legend()
# plt.subplot(3, 1, 2)
# plt.plot(sig.freqz(hamming_filter)[0], 20 * np.log10(abs(sig.freqz(hamming_filter)[1])), color="C1", label='Hamming filter')
# plt.ylabel('Amplitude [dB]')
# plt.xlabel('Frequency [rad/sample]')
# plt.legend()
# plt.subplot(3, 1, 3)
# plt.plot(sig.freqz(blackman_filter)[0], 20 * np.log10(abs(sig.freqz(blackman_filter)[1])), color="C2", label='Blackman filter')
# plt.ylabel('Amplitude [dB]')
# plt.xlabel('Frequency [rad/sample]')
# plt.tight_layout()
# plt.legend(fontsize="larger")
# plt.show()


# Apply the filter to the noisy data using the scipy.signal.convolve() function
bartlett_filtered_data = sig.convolve(Input_1kHz_15kHz, bartlett_filter, mode='same') / sum(bartlett_filter)
hamming_filtered_data = sig.convolve(Input_1kHz_15kHz, hamming_filter, mode='same') / sum(hamming_filter)
blackman_filtered_data = sig.convolve(Input_1kHz_15kHz, blackman_filter, mode='same') / sum(blackman_filter)


# # Plot the results in rows of 4 subplots
# fig, axs = plt.subplots(4, 1, figsize=(10, 10))
# fig.suptitle('Fig.3: FIR Comparison of Bartlett, Hamming, Blackman filters Outputs in Time Domain')
# axs[0].plot(Input_1kHz_15kHz, color="C0", label='Original data')
# axs[0].set_title('Original data')
# axs[1].plot(bartlett_filtered_data, color="C1", label='Bartlett filtered data')
# axs[1].set_title('Bartlett filtered data')
# axs[2].plot(hamming_filtered_data, color="C2", label='Hamming filtered data')
# axs[2].set_title('Hamming filtered data')
# axs[3].plot(blackman_filtered_data, color="C3", label='Blackman filtered data')
# axs[3].set_title('Blackman filtered data')
# for ax in axs.flat:
#     ax.set(xlabel='Time', ylabel='Amplitude')
#     ax.label_outer()
# plt.show()

# # Plot the filtered data and original data in the same figure to compare them visually
# plt.figure("Fig.4: Stacked FIR Comparison of Bartlett, Hamming, Blackman filters Outputs in Time Domain", figsize=(10, 10))
# plt.suptitle('Fig.4: Stacked FIR Comparison of Bartlett, Hamming, Blackman filters Outputs in Time Domain')
# plt.plot(Input_1kHz_15kHz, color="C0", label='Original data')
# plt.plot(bartlett_filtered_data, color="C1", label='Bartlett filtered data')
# plt.plot(hamming_filtered_data, color="C2", label='Hamming filtered data')
# plt.plot(blackman_filtered_data, color="C3", label='Blackman filtered data')
# plt.xlabel('Time')
# plt.ylabel('Amplitude')
# plt.legend(loc="lower center", bbox_to_anchor=[0.5, 1], ncol=2, fontsize="larger")
# plt.show()

# plot the the filtered data in dB scale and in rows of subplots using numpy.fft.fft() function
plt.figure("Fig.5: FIR Comparison of Bartlett, Hamming, Blackman filters Outputs in Frequency Domain", figsize=(10, 10))
plt.suptitle('Fig.5: FIR Comparison of Bartlett, Hamming, Blackman filters Outputs in Frequency Domain')
plt.subplot(3, 1, 1)
plt.plot(np.fft.fft(Input_1kHz_15kHz), color="C0", label='Original data')
plt.ylabel('Amplitude [dB]')
plt.xlabel('Frequency [rad/sample]')
plt.legend()
plt.subplot(3, 1, 2)
plt.plot(np.fft.fft(bartlett_filtered_data), color="C1", label='Bartlett filtered data')
plt.ylabel('Amplitude [dB]')
plt.xlabel('Frequency [rad/sample]')
plt.legend()
plt.subplot(3, 1, 3)
plt.plot(np.fft.fft(hamming_filtered_data), color="C2", label='Hamming filtered data')
plt.ylabel('Amplitude [dB]')
plt.xlabel('Frequency [rad/sample]')
plt.tight_layout()
plt.legend(fontsize="larger")
plt.show()
