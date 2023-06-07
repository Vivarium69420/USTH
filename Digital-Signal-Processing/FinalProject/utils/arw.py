from scipy.io import wavfile

def read_wav(path):
    rate, data = wavfile.read(path)
    data_mono = data[:,0]
    return rate, data_mono # (rate, data)

def write_wav(path, rate, data): 
    path = '/filtered_audio_files/' + path + '.wav'
    wavfile.write(path, rate, data)
